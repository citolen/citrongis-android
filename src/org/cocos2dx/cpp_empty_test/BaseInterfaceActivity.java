package org.cocos2dx.cpp_empty_test;

import org.tools.FontsOverride;

import android.app.ActionBar;
import android.content.Context;
import android.content.Intent;
import android.os.Bundle;
import android.support.v7.app.ActionBarActivity;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.TextView;

public class BaseInterfaceActivity extends ActionBarActivity {
	
	/*
	 * Action bar title
	 */
	protected String mActivityName;

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);

		this.overridePendingTransition(R.anim.activity_animation_enter_left, R.anim.activity_animation_leave_left);
		
		/* Override default font */
		FontsOverride.setDefaultFont(this, "DEFAULT", "fonts/Nexa Bold.otf");
		
		/* Override default action bar */
		getSupportActionBar().setDisplayOptions(ActionBar.DISPLAY_SHOW_CUSTOM); 
		getSupportActionBar().setCustomView(R.layout.actionbar);
		TextView actionbar_title = (TextView) findViewById(R.id.actionbar_title);
		actionbar_title.setText(mActivityName);
		
		/* Set action bar return button on click listener */
		Button return_button = (Button) findViewById(R.id.actionbar_return);
		return_button.setOnClickListener(new OnClickListener() {
			
			@Override
			public void onClick(View v) {
				closeActivity();
			}
		});
	}
	
	@Override
	protected void onStart() {
		super.onStart();
	}
	
	@Override
	protected void onResume() {
		super.onResume();
	}
	
	@Override
	protected void onPause() {
		super.onPause();
		this.overridePendingTransition(R.anim.activity_animation_enter_right, R.anim.activity_animation_leave_right);
	}
	
	@Override
	protected void onStop() {
		super.onStop();
	}
	
	@Override
	protected void onDestroy() {
		super.onDestroy();
	}
	
	public void closeActivity() {
		this.finish();
	}
	
	public class StartNewActivity implements OnClickListener {
		
		private Context mContext;
		protected Class<?> mActivityClass;
		
		public StartNewActivity(Class<?> activityClass, Context context) {
			mContext = context;
			mActivityClass = activityClass;
		}
		
		@Override
		public void onClick(View v) {

			Intent intent = new Intent(mContext, mActivityClass);
            startActivity(intent);
			
		}
		
	}
}
