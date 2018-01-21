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

package org.lineageos.settings.device;

import android.content.Context;
import android.view.KeyEvent;
import android.view.WindowManager;

import com.android.internal.os.DeviceKeyHandler;

public class KeyHandler implements DeviceKeyHandler {

    private static final int KEY_PEN_DTU = 0x2f1;
    private static final int KEY_PEN_UTD = 0x2f2;
    private static final int KEY_PEN_RTL = 0x2f3;
    private static final int KEY_PEN_LTR = 0x2f4;
    private static final int KEY_PEN_LP = 0x2f5;

    private static final int[] ROTATION_0_MAP = {
        KEY_PEN_DTU,
        KEY_PEN_UTD,
        KEY_PEN_RTL,
        KEY_PEN_LTR,
        KEY_PEN_LP,
    };
    private static final int[] ROTATION_90_MAP = {
        KEY_PEN_RTL,
        KEY_PEN_LTR,
        KEY_PEN_UTD,
        KEY_PEN_DTU,
        KEY_PEN_LP,
    };
    private static final int[] ROTATION_180_MAP = {
        KEY_PEN_UTD,
        KEY_PEN_DTU,
        KEY_PEN_LTR,
        KEY_PEN_RTL,
        KEY_PEN_LP,
    };
    private static final int[] ROTATION_270_MAP = {
        KEY_PEN_LTR,
        KEY_PEN_RTL,
        KEY_PEN_DTU,
        KEY_PEN_UTD,
        KEY_PEN_LP,
    };

    private static final int[][] ROTATION_MAP = {
        ROTATION_0_MAP,
        ROTATION_90_MAP,
        ROTATION_180_MAP,
        ROTATION_270_MAP,
    };

    private final Context mContext;

    public KeyHandler(Context context) {
        mContext = context;
    }

    public KeyEvent handleKeyEvent(KeyEvent event) {
        final int rotation = ((WindowManager) mContext.getSystemService(Context.WINDOW_SERVICE))
                .getDefaultDisplay().getRotation();

        if (event.getScanCode() >= KEY_PEN_DTU && event.getScanCode() <= KEY_PEN_LP) {
            event = new KeyEvent(event.getDownTime(), event.getEventTime(), event.getAction(),
                    event.getKeyCode(), event.getRepeatCount(), event.getMetaState(),
                    event.getDeviceId(), ROTATION_MAP[rotation][event.getScanCode() - KEY_PEN_DTU],
                    event.getFlags(), event.getSource());
        }

        return event;
    }
}
