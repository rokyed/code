/// @file Settings for texture loading and handling.

//#include "texture/texsettings.h"

#include "inexor/engine/engine.h"

VAR(hwtexsize, 1, 0, 0);
VAR(hwcubetexsize, 1, 0, 0);
VAR(hwmaxaniso, 1, 0, 0);
VARFP(maxtexsize, 0, 0, 1 << 12, initwarning("texture quality", INIT_LOAD));
VARFP(reducefilter, 0, 1, 1, initwarning("texture quality", INIT_LOAD));
VARFP(texreduce, 0, 0, 12, initwarning("texture quality", INIT_LOAD));
VARFP(trilinear, 0, 1, 1, initwarning("texture filtering", INIT_LOAD));
VARFP(bilinear, 0, 1, 1, initwarning("texture filtering", INIT_LOAD));
VARFP(aniso, 0, 0, 16, initwarning("texture filtering", INIT_LOAD));


VARFP(texcompress, 0, 1 << 10, 1 << 12, initwarning("texture quality", INIT_LOAD));
VARFP(texcompressquality, -1, -1, 1, setuptexcompress());

VARFP(hwmipmap, 0, 0, 1, initwarning("texture filtering", INIT_LOAD));
VARFP(usenp2, 0, 0, 1, initwarning("texture quality", INIT_LOAD));

extern int usetexcompress; // from rendergl

texsettings::texsettings() : maxtexsize(::maxtexsize), reducefilter(::reducefilter), texreduce(::texreduce),
                            trilinear(::trilinear), bilinear(::bilinear), aniso(::aniso), hwmipmap(::hwmipmap),
                            texcompress(::texcompress), texcompressquality(::texcompressquality), usenp2(::usenp2),
                            hwtexsize(::hwtexsize), hwcubetexsize(::hwcubetexsize), hwmaxaniso(::hwmaxaniso),
                            renderpath(::renderpath), usetexcompress(::usetexcompress), 
                            hasTC(::hasTC), hasAF(::hasAF), hasGM(::hasGM), hasNP2(::hasNP2) {}
