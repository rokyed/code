/// @file Settings for texture loading and handling.

#ifndef _TEX_SETTINGS_H
#define _TEX_SETTINGS_H

/// Structure to hold all useful texture settings, to be used in a threaded environment.
struct texsettings
{
    // All settings specified by the user, matter of taste.
    int maxtexsize, reducefilter, texreduce, trilinear, bilinear,
    aniso, texcompress, texcompressquality, hwmipmap, usenp2;

    // Settings the platform dictates.
    int hwtexsize, hwcubetexsize, hwmaxaniso;

    // Actually not part of texsettings but rendersettings (which is not yet made):
    int renderpath,
        usetexcompress,
        hasTC, hasAF, hasGM, hasNP2;

    /// Load all data according to the global vars, which we cant use simoultanously from different threads.
    texsettings();
};

#endif // _TEX_SETTINGS_H
