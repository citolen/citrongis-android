package org.models;

import org.cocos2dx.cpp_empty_test.R;

import android.content.Context;
import android.graphics.Color;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseAdapter;
import android.widget.ImageView;


public class ImageAdapter extends BaseAdapter {

    public ImageAdapter(Context c) {
        int[] colors = {
        		Color.rgb(26, 188, 156),
        		Color.rgb(46, 204, 113),
        		Color.rgb(241, 196, 15),
        		Color.rgb(230, 126, 34),
        		Color.rgb(52, 152, 219)
        };

	    final float scale = c.getResources().getDisplayMetrics().density;
	    int padding_in_px = (int) (30 * scale + 0.5f);
        mThumbs = new ImaveViewAutoSize[5];
        for (int i = 0; i < mThumbIds.length; i++) {
			mThumbs[i] = new ImaveViewAutoSize(c);
			mThumbs[i].setBackgroundColor(colors[i]);
			mThumbs[i].setScaleType(ImageView.ScaleType.CENTER_CROP);
			mThumbs[i].setImageResource(mThumbIds[i]);
			mThumbs[i].setPadding(padding_in_px, padding_in_px, padding_in_px, padding_in_px);
		}
    }

    public int getCount() {
        return mThumbs.length;
    }

    public Object getItem(int position) {
        return mThumbIds[position];
    }

    public long getItemId(int position) {
        return mThumbIds[position];
    }

	@Override
	public View getView(int position, View convertView, ViewGroup parent) {
		return mThumbs[position];
	}

	private ImaveViewAutoSize[] mThumbs;
	

    Integer[] mThumbIds = {
            R.drawable.menu_user,
            R.drawable.menu_bag,
            R.drawable.menu_search,
            R.drawable.menu_settings,
            R.drawable.menu_applications,
    };
}