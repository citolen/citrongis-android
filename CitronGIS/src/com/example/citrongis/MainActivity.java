package com.example.citrongis;

import android.os.Bundle;
import android.app.Activity;
import android.util.Log;
import android.view.Menu;
import org.proj4.PJ;

public class MainActivity extends Activity {

	static {
        System.loadLibrary("CitronGIS");
    }
	
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
		
        Log.d("PROJ4", PJ.getVersion());
	}

	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		// Inflate the menu; this adds items to the action bar if it is present.
		getMenuInflater().inflate(R.menu.main, menu);
		return true;
	}

}
