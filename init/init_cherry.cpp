/*
   Copyright (c) 2014, The Linux Foundation. All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are
   met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above
      copyright notice, this list of conditions and the following
      disclaimer in the documentation and/or other materials provided
      with the distribution.
    * Neither the name of The Linux Foundation nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
   WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
   ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
   BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
   BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
   WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
   OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
   IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <cstdlib>
#include <fstream>
#include <string>

#include "vendor_init.h"
#include "property_service.h"
#include "log.h"
#include "util.h"

#define ISMATCH(a,b)    (!strncmp(a,b,PROP_VALUE_MAX))

void vendor_load_properties()
{
    char platform[PROP_VALUE_MAX];
    std::ifstream fin;
    std::string buf;
    int rc;

    rc = property_get("ro.board.platform", platform);
    if (!rc || !ISMATCH(platform, ANDROID_TARGET))
        return;

    fin.open("/proc/app_info");
    while (getline(fin, buf))
        if (buf.find("huawei_fac_product_name") != std::string::npos)
            break;
    fin.close();

    /* C8817D */
    if (buf.find("C8817D") != std::string::npos) {
        property_set("ro.product.model", "C8817D");
        property_set("ro.product.device", "C8817D");
        property_set("ro.build.product", "C8817D");
        property_set("persist.radio.multisim.config", "dsds");
        property_set("ro.build.description", "C8817D-user 4.4.4 GRJ90 C92B381 release-keys");
        property_set("ro.build.fingerprint", "Huawei/C8817D/hwC8817D:4.4.4/HuaweiC8817D/C92B381:user/release-keys");
    }
    /* C8817E */
    else if (buf.find("C8817E") != std::string::npos) {
        property_set("ro.product.model", "C8817E");
        property_set("ro.product.device", "C8817E");
        property_set("ro.build.product", "C8817E");
        property_set("ro.build.description", "C8817E-user 4.4.4 GRJ90 C92B380 release-keys");
        property_set("ro.build.fingerprint", "Huawei/C8817E/hwC8817E:4.4.4/HuaweiC8817E/C92B380:user/release-keys");
    }
    /* G621-TL00 */
    else if (buf.find("G621-TL00") != std::string::npos) {
        property_set("ro.product.model", "G621-TL00");
        property_set("ro.product.device", "G621-TL00");
        property_set("ro.build.product", "G621-TL00");
        property_set("persist.radio.multisim.config", "dsds");
        property_set("ro.build.description", "G621-TL00-user 4.4.4 GRJ90 C01B361SP01 release-keys");
        property_set("ro.build.fingerprint", "Honor/G621-TL00/hwG621-TL00:4.4.4/HonorG621-TL00/C01B361SP01:user/release-keys");
    }
    /* G620S-UL00 */
    else if (buf.find("G620S-UL") != std::string::npos) {
        property_set("ro.product.model", "G620S-UL00");
        property_set("ro.product.device", "G620S-UL00");
        property_set("ro.build.product", "G620S-UL00");
        property_set("persist.radio.multisim.config", "dsds");
        property_set("ro.build.description", "G620S-UL00-user 4.4.4 GRJ90 C17B246 release-keys");
        property_set("ro.build.fingerprint", "Huawei/G620S-UL00/hwG620S-UL00:4.4.4/HuaweiG620S-UL00/C17B246:user/release-keys");
    }
    /* G620S-L01 */
    else if (buf.find("G620S-L01") != std::string::npos) {
        property_set("ro.product.model", "G620S-L01");
        property_set("ro.product.device", "G620S-L01");
        property_set("ro.build.product", "G620S-L01");
        property_set("ro.build.description", "G620S-L01-user 4.4.4 GRJ90 C00B380 release-keys");
        property_set("ro.build.fingerprint", "Huawei/G620S-L01/hwG620S-L01:4.4.4/HuaweiG620S-L01/C00B380:user/release-keys");
    }
    /* G620S-L02 */
    else if (buf.find("G620S-L02") != std::string::npos) {
        property_set("ro.product.model", "G620S-L02");
        property_set("ro.product.device", "G620S-L02");
        property_set("ro.build.product", "G620S-L02");
        property_set("ro.build.description", "G620S-L02-user 4.4.4 GRJ90 C00B380 release-keys");
        property_set("ro.build.fingerprint", "Huawei/G620S-L02/hwG620S-L02:4.4.4/HuaweiG620S-L02/C00B380:user/release-keys");
    }
    /* Che1-CL10 */
    else if (buf.find("Che1-CL10") != std::string::npos) {
        property_set("ro.product.model", "Che1-CL10");
        property_set("ro.product.device", "Che1-CL10");
        property_set("ro.build.product", "Che1-CL10");
        property_set("persist.radio.multisim.config", "dsds");
        property_set("ro.build.description", "Che1-CL10-user 4.4.4 GRJ90 C92B275 release-keys");
        property_set("ro.build.fingerprint", "Honor/Che1-CL10/Che1:4.4.4/Che1-CL10/C92B275:user/ota-rel-keys,release-keys");
    }
    /* Che1-CL20 */
    else if (buf.find("Che1-CL20") != std::string::npos) {
        property_set("ro.product.model", "Che1-CL20");
        property_set("ro.product.device", "Che1-CL20");
        property_set("ro.build.product", "Che1-CL20");
        property_set("persist.radio.multisim.config", "dsds");
        property_set("ro.build.description", "Che1-CL20-user 4.4.4 GRJ90 C00B275 release-keys");
        property_set("ro.build.fingerprint", "Honor/Che1-CL20/Che1:4.4.4/Che1-CL20/C00B275:user/ota-rel-keys,release-keys");
    }
    /* Che1-L04 */
    else if (buf.find("Che1-L04") != std::string::npos) {
        property_set("ro.product.model", "Che1-L04");
        property_set("ro.product.device", "Che1-L04");
        property_set("ro.build.product", "Che1-L04");
        property_set("persist.radio.multisim.config", "dsds");
        property_set("ro.build.description", "Che1-L04-user 4.4.4 GRJ90 C900B130 release-keys");
        property_set("ro.build.fingerprint", "Honor/Che1-L04/Che1:4.4.4/Che1-L04/C900B130:user/ota-rel-keys,release-keys");
    }
}
