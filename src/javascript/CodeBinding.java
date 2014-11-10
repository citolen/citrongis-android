package javascript;

import android.content.Context;
import android.widget.Toast;

public class CodeBinding {

	private Context mContext;
	
	public CodeBinding(Context context) {
		mContext = context;
	}
	
	public void showToast(String str) {
		Toast.makeText(mContext, str, Toast.LENGTH_LONG).show();
	}
}
