package org.cocos2dx.cpp_empty_test;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;

public class GeneralConditionsActivity extends BaseInterfaceActivity {

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.mActivityName = "General Conditions";
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_general_conditions);
		
		final GeneralConditionsActivity context = this;
		
		Button decline = (Button)findViewById(R.id.button_decline);
		decline.setOnClickListener(new OnClickListener() {
			@Override
			public void onClick(View v) {
				Intent intent = new Intent();
				intent.putExtra("conditions","declined");
				setResult(RESULT_OK, intent);
				context.finish();
			}
		});
		Button accept = (Button)findViewById(R.id.button_accept);
		accept.setOnClickListener(new OnClickListener() {
			@Override
			public void onClick(View v) {
				Intent intent = new Intent();
				intent.putExtra("conditions","accepted");
				setResult(RESULT_OK, intent);
				context.finish();
			}
		});
	}
}
