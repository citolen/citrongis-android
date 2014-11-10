package org.cocos2dx.cpp_empty_test;

import org.models.OpenWebPage;

import android.os.Bundle;
import android.widget.Button;
import android.widget.ImageView;

public class LoginActivity extends BaseInterfaceActivity {

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.mActivityName = "Sign in";
		super.onCreate(savedInstanceState);

		setContentView(R.layout.activity_login);
		
		ImageView img = (ImageView)findViewById(R.id.logo_image_facebook);
		img.setOnClickListener(new OpenWebPage("http://www.google.fr", this));
		
		img = (ImageView)findViewById(R.id.logo_image_googlep);
		img.setOnClickListener(new OpenWebPage("http://www.google.fr", this));

		img = (ImageView)findViewById(R.id.logo_image_twitter);
		img.setOnClickListener(new OpenWebPage("http://www.google.fr", this));
		
		Button signup = (Button)findViewById(R.id.button_signup);
		signup.setOnClickListener(new StartNewActivity(SignupActivity.class, this));
	}

}
