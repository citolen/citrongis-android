package org.models;

import android.content.Context;
import android.util.AttributeSet;
import android.widget.ImageView;

public class ImaveViewAutoSize extends ImageView {

	public ImaveViewAutoSize(Context context) {
		super(context);
	}

	public ImaveViewAutoSize(Context context, AttributeSet attrs) {
		super(context, attrs);
	}

	public ImaveViewAutoSize(Context context, AttributeSet attrs, int defStyle) {
		super(context, attrs, defStyle);
	}

	@Override
	protected void onMeasure(int widthMeasureSpec, int heightMeasureSpec){
		super.onMeasure(widthMeasureSpec,heightMeasureSpec);
		setMeasuredDimension(getMeasuredWidth(),getMeasuredWidth());
	}
}
