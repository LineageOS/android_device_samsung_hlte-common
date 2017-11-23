/*
 * Copyright (C) 2017 The LineageOS Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

package org.lineageos.gesturerotation;

import android.app.Service;
import android.content.Context;
import android.content.Intent;
import android.content.res.Configuration;
import android.os.IBinder;
import android.view.WindowManager;

import org.cyanogenmod.internal.util.FileUtils;

public class GestureRotationService extends Service {
    private static final String ROTATION_PATH = "/sys/class/sec/sec_epen/epen_gesture_rotation";

    private void getAndSetRotation() {
        final int rotation = ((WindowManager) this.getSystemService(Context.WINDOW_SERVICE))
                .getDefaultDisplay().getRotation();
        FileUtils.writeLine(ROTATION_PATH, String.valueOf(rotation));
    }

    @Override
    public IBinder onBind(Intent intent) {
        return null;
    }

    @Override
    public void onConfigurationChanged(Configuration newConfig) {
        super.onConfigurationChanged(newConfig);
        getAndSetRotation();
    }

    @Override
    public void onCreate() {
        super.onCreate();
        getAndSetRotation();
    }

    @Override
    public void onDestroy() {
        super.onDestroy();
        getAndSetRotation();
    }

    @Override
    public int onStartCommand(Intent intent, int flags, int startId) {
        getAndSetRotation();
        return START_STICKY;
    }

    @Override
    public void onTaskRemoved(Intent rootIntent) {
        super.onTaskRemoved(rootIntent);
        getAndSetRotation();
    }
}
