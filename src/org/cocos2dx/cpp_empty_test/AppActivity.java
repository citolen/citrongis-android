/****************************************************************************
Copyright (c) 2010-2012 cocos2d-x.org

http://www.cocos2d-x.org

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
****************************************************************************/
package org.cocos2dx.cpp_empty_test;

import java.io.BufferedInputStream;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.StringWriter;

import javascript.CodeBinding;

import org.cocos2dx.lib.Cocos2dxActivity;
import org.models.ImageAdapter;

import android.annotation.SuppressLint;
import android.app.ActionBar.LayoutParams;
import android.content.Context;
import android.content.Intent;
import android.content.res.AssetManager;
import android.os.Bundle;
import android.support.v4.widget.DrawerLayout;
import android.util.Base64;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.MotionEvent;
import android.view.View;
import android.view.View.OnClickListener;
import android.view.View.OnTouchListener;
import android.webkit.ConsoleMessage;
import android.webkit.WebChromeClient;
import android.webkit.WebView;
import android.widget.AdapterView;
import android.widget.AdapterView.OnItemClickListener;
import android.widget.Button;
import android.widget.GridView;
import android.widget.RelativeLayout;

public class AppActivity extends Cocos2dxActivity {
	/*
	 * Load external librairies
	 */
	static {
		System.loadLibrary("proj");
	}
	
	/*
	 * Constants
	 */
	private final static String TAG = AppActivity.class.getSimpleName();
    private View mCocos2dxView;
    
    private WebView mWebView;
    
	@SuppressLint("NewApi")
	@Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        
        /*
         * Set main view
         */
        LayoutInflater factory = getLayoutInflater();
		DrawerLayout drawerLayout = (DrawerLayout)factory.inflate(R.layout.main_layout, null);
		setContentView(drawerLayout);
		
		/*
		 * Add Cocos2dx view
		 */
		mCocos2dxView = super.mFrameLayout;
		RelativeLayout frameLayout = (RelativeLayout) findViewById(R.id.content_frame);
		frameLayout.addView(mCocos2dxView, 0);
		
		/*
		 * Add SideBar
		 */
		initSideBar();
		
//		Button btn = new Button(this);
//		btn.setText("call jsfunc");
//		btn.setLayoutParams(new LayoutParams(LayoutParams.WRAP_CONTENT, LayoutParams.WRAP_CONTENT));
//		btn.setOnClickListener(new OnClickListener() {
//			
//			@Override
//			public void onClick(View v) {
//				myButtonClicked(v);
//			}
//		});
//		frameLayout.addView(btn);
		
		/*
		 * Add Web view
		 */
		initWebView();
    }
	
	private void initSideBar() {
		GridView gridview = (GridView) findViewById(R.id.left_drawer);
		final ImageAdapter imageAdapter = new ImageAdapter(this);
	    gridview.setAdapter(imageAdapter);
	    final Context context = this;

	    gridview.setOnItemClickListener(new OnItemClickListener() {
	        public void onItemClick(AdapterView<?> parent, View v, int position, long id) {
	            if ((Integer)imageAdapter.getItem(position) == R.drawable.menu_user) {
	            	Intent intent = new Intent(context, LoginActivity.class);
	                startActivity(intent);
	            } else if ((Integer)imageAdapter.getItem(position) == R.drawable.menu_applications) {
	        		LoadTestExtentions("extensions/citrongis-app.zip");
	        		LoadTestExtentions("extensions/chat.zip");
	        		LoadTestExtentions("extensions/chat1.zip");
	            }
	        }
	    });
	}

	/*
	 * Web View for javascript
	 */
	@SuppressLint("SetJavaScriptEnabled")
	private void initWebView() {
		mWebView = (WebView) findViewById(R.id.main_webView);
		
		mWebView.setWebChromeClient(new WebChromeClient() {
		  public boolean onConsoleMessage(ConsoleMessage cm) {
		    Log.d("WebView", cm.message() + " -- From line "
		                         + cm.lineNumber() + " of "
		                         + cm.sourceId() );
		    return true;
		  }
		});
		
		mWebView.setOnTouchListener(new OnTouchListener() {
			
			@Override
			public boolean onTouch(View v, MotionEvent event) {
				mCocos2dxView.dispatchTouchEvent(event); // Send event to cocos2dx view
				return false;
			}
		});
		mWebView.getSettings().setJavaScriptEnabled(true); // Unable javascript
		mWebView.getSettings().setBuiltInZoomControls(true); // Disable Zoom
		mWebView.loadUrl("file:///android_asset/www/JavascriptLoader.html");
//		mWebView.addJavascriptInterface(new CodeBinding(this), "Android");
		mWebView.setBackgroundColor(0x00000000); // Set WebView transparent
	}
	
//	public void myButtonClicked(View view) {
//		
//	     Log.d(TAG, "my button cliked");
//	     
//	     runOnUiThread(new Runnable() {
//			@Override
//			public void run() {
//			     WebView webView = (WebView) findViewById(R.id.main_webView);
//			     webView.loadUrl("javascript:jsfunc()");
//			}
//		});
//	 }
	
	private void LoadTestExtentions(String path) {
		AssetManager assetManager = this.getAssets();
		try {
			InputStream is = assetManager.open(path);
			int n = 0;
		    byte[] buffer = new byte[1024 * 4];
			StringBuilder sb = new StringBuilder();
			while (-1 != (n = is.read(buffer)))
				sb.append(new String(Base64.encode(buffer, 0, n, Base64.DEFAULT)));
		    
			mWebView.loadUrl("javascript:LoadExtention('"+sb.toString()+"');");
			
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}