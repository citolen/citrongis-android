package com.example.citrongis;

import java.io.Console;

import android.app.Activity;
import android.os.Bundle;
import android.util.Log;
import android.view.Menu;
import android.view.MotionEvent;
import android.widget.TextView;
import android.widget.Toast;


public class MainActivity extends Activity {
	static {
        System.loadLibrary("proj");
        System.loadLibrary("CitronGIS");
    }
	public native String getVersion();
	public native String getAutors();
	
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
	
		String text = getVersion();
		String autors = getAutors();
		TextView view = (TextView) findViewById(R.id.textView);
		view.setText(text + autors);
	}

	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		// Inflate the menu; this adds items to the action bar if it is present.
		getMenuInflater().inflate(R.menu.main, menu);
		return true;
	}
	
	@Override
	public boolean onTouchEvent(MotionEvent event)
	{
	    int X = (int) event.getX();
	    int Y = (int) event.getY();
	    int eventaction = event.getAction();

	    if (X < 200 && Y < 200)
	    {
	        Toast.makeText(this, "CHAMPION !!!!! :)", Toast.LENGTH_SHORT).show();	    
	    }
	    if (eventaction == MotionEvent.ACTION_DOWN)
	    {
	        Log.e(TEXT_SERVICES_MANAGER_SERVICE, "ACTION_DOWN AT COORDS "+"X: "+X+" Y: "+Y);
	    }
	    else if (eventaction == MotionEvent.ACTION_MOVE)
	    {
	        Log.e(TEXT_SERVICES_MANAGER_SERVICE, "MOVE "+"X: "+X+" Y: "+Y);
	    }
	    else if (eventaction == MotionEvent.ACTION_UP)
	    {
	        Log.e(TEXT_SERVICES_MANAGER_SERVICE, "ACTION_UP "+"X: "+X+" Y: "+Y);

	    }

	    return true;
	}
}