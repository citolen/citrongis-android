package org.cocos2dx.cpp_empty_test;

import android.content.Context;
import android.content.Intent;
import android.os.Bundle;
import android.text.SpannableString;
import android.text.method.LinkMovementMethod;
import android.text.method.MovementMethod;
import android.text.style.ClickableSpan;
import android.view.View;
import android.widget.TextView;

public class SignupActivity extends BaseInterfaceActivity {

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.mActivityName = "Sign up";
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_signup);
		
		final Context context = this;
		
		SpannableString link = makeLinkSpan(getString(R.string.activity_signup_form_generalconditions_link), new View.OnClickListener() {          
	        @Override
	        public void onClick(View v) {
	        	Intent intent = new Intent(context, GeneralConditionsActivity.class);
	            startActivity(intent);
	        }
	    });
		
		TextView tv = (TextView)findViewById(R.id.generalconditions_textview);
		tv.append(" ");
	    tv.append(link);
	    makeLinksFocusable(tv);
	}
	
	private SpannableString makeLinkSpan(CharSequence text, View.OnClickListener listener) {
	    SpannableString link = new SpannableString(text);
	    link.setSpan(new ClickableString(listener), 0, text.length(), 
	        SpannableString.SPAN_INCLUSIVE_EXCLUSIVE);
	    return link;
	}
	
	private void makeLinksFocusable(TextView tv) {
	    MovementMethod m = tv.getMovementMethod();  
	    if ((m == null) || !(m instanceof LinkMovementMethod)) {  
	        if (tv.getLinksClickable()) {  
	            tv.setMovementMethod(LinkMovementMethod.getInstance());  
	        }  
	    }  
	}
	
	private static class ClickableString extends ClickableSpan {  
	    private View.OnClickListener mListener;          
	    public ClickableString(View.OnClickListener listener) {              
	        mListener = listener;  
	    }          
	    @Override  
	    public void onClick(View v) {  
	        mListener.onClick(v);  
	    }        
	}
}
