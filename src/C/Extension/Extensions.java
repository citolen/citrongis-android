package C.Extension;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.UnsupportedEncodingException;
import java.util.zip.ZipEntry;
import java.util.zip.ZipInputStream;

import org.apache.commons.io.IOUtils;
import org.json.JSONException;
import org.json.JSONObject;

import android.content.Context;
import android.util.JsonReader;
import android.util.Log;

public class Extensions {

	private static final String TAG = "Extensions";
	private static final String AR_STRINGS_LOCALIZATION = "strings.json";
	private static final String AR_PACKAGE = "package.json";
	
	private File mExt_folder;
	private JSONObject mPackage;
	private C.Extension.Module mModule;

	public Extensions(InputStream zipfile, Context context) throws IOException {

		mPackage = new JSONObject();
		
		/* Load the package.json */
		LoadExtensionConfig(zipfile);
		
		zipfile.reset();
		
		/* Extract the extension forlder */
		try {
			mExt_folder = new File(context.getFilesDir().getPath(), (String) mPackage.get("name"));
			ParseAndExtract(zipfile, mExt_folder);
		} catch (JSONException e) {
			e.printStackTrace();
		}
		
		zipfile.close();
		
		this.mModule = new C.Extension.Module("strings file content");
		
		this.debugPackage();
	}
	
	public void run() {
	}
	
	public void setupEnvironment() {
	}
	
	public void debugPackage() {
		Log.d(TAG, this.mPackage.toString());
	}
	
	private void ParseAndExtract(InputStream zipfile, File extractFolder) throws IOException {
		
		if (!extractFolder.exists()) {
			if (!extractFolder.mkdir())
				Log.d(TAG, "Can not create extension directory");
		}
		
		if (extractFolder.exists()) {
			Log.d(TAG, "extractFolder exists");
		} else {
			Log.d(TAG, "extractFolder do not exists");
		}
		
		ZipInputStream zis = new ZipInputStream(zipfile);
		byte[] buffer = new byte[1024];
		int len;
		
		ZipEntry ze;
		while ((ze = zis.getNextEntry()) != null) {
			File extractFile = new File(extractFolder, ze.getName());
			Log.d(TAG, "Found " + ze.getName() + " : " + extractFile.getPath());
			if (!ze.isDirectory()) {
				FileOutputStream fout = new FileOutputStream(extractFile);
				while ((len = zis.read(buffer)) > 0)
					fout.write(buffer, 0, len);
				fout.close();
			} else if (!extractFile.exists()) {
				if (!extractFile.mkdirs())
					Log.d(TAG, "Cannot create directory");
			}
		}
		zis.closeEntry();
	}
	
	private void LoadExtensionConfig(InputStream zipfile) throws IOException {
		ZipInputStream zis = new ZipInputStream(zipfile);
		ZipEntry ze;
		while ((ze = zis.getNextEntry()) != null) {
			if (ze.getName().equals(AR_PACKAGE)) {
				try {
					String json = IOUtils.toString(zis, "UTF-8");
					this.mPackage = new JSONObject(json);
				} catch (IOException | JSONException e) {
					e.printStackTrace();
				}
			}
		}
		zis.closeEntry();
	}
}
