/// @file Settings for texture loading and handling.

#include "inexor/engine/engine.h"
#include "inexor/texture/texsettings.h"

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

VAR(usedds, 0, 1, 1);
VAR(scaledds, 0, 2, 4);

extern int usetexcompress; // from rendergl

void texsettings::updateall()
{
    maxtexsize = ::maxtexsize; reducefilter = ::reducefilter; texreduce = ::texreduce;
    trilinear = ::trilinear; bilinear = ::bilinear; aniso = ::aniso; texcompress = ::texcompress;
    texcompressquality = ::texcompressquality; hwmipmap = ::hwmipmap; usenp2 = ::usenp2;
    hwtexsize = ::hwtexsize; hwcubetexsize = ::hwcubetexsize; hwmaxaniso = ::hwmaxaniso;
    renderpath = ::renderpath; usetexcompress = ::usetexcompress;
    usedds = ::usedds; scaledds = ::scaledds; maxtmus = ::maxtmus;
    hasTC = ::hasTC; hasAF = ::hasAF; hasCM = ::hasCM; hasGM = ::hasGM; hasNP2 = ::hasNP2;
}

static texsettings legacysets;
texsettings *legacytexsettings()
{
    legacysets.updateall(); // todo: oben vermischen
    return &legacysets;
}
