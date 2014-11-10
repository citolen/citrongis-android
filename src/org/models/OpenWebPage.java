package org.models;

import android.content.Context;
import android.content.Intent;
import android.net.Uri;
import android.view.View;

public class OpenWebPage implements View.OnClickListener {
	
	protected String mUrl;
	private Context mContext;
	
	public OpenWebPage(String url, Context context) {
		mUrl = url;
		mContext = context;
	}
	
	@Override
	public void onClick(View v) {
        Intent intent = new Intent();
        intent.setAction(Intent.ACTION_VIEW);
        intent.addCategory(Intent.CATEGORY_BROWSABLE);
        intent.setData(Uri.parse(mUrl));
        mContext.startActivity(intent);
	}
	
}