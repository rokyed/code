// This file gets generated!
// Do not modify it directly but its corresponding template file instead! 

#pragma once

#include <unordered_map>

#include "inexor/rpc/treedata.gen.grpc.pb.h"

#include "inexor/rpc/SharedTree.hpp"
#include "inexor/rpc/RpcSubsystem.hpp"


// List of extern SharedVar declarations

    extern SharedVar<int> guiautotab;


    extern SharedVar<int> guiclicktab;


    extern SharedVar<int> guifadein;


    extern SharedVar<int> guipushdist;


    extern SharedVar<float> guisens;


    extern SharedVar<int> useguifollow;


    extern SharedVar<int> usegui2d;


    extern SharedVar<int> envmapmodels;


    extern SharedVar<int> bumpmodels;


    extern SharedVar<int> fullbrightmodels;


    extern SharedVar<int> blendpaintmode;


    extern SharedVar<int> paintblendmapdelay;


    extern SharedVar<int> paintblendmapinterval;


    extern SharedVar<int> showblobs;


    extern SharedVar<int> blobintensity;


    extern SharedVar<int> blobheight;


    extern SharedVar<int> blobfadelow;


    extern SharedVar<int> blobfadehigh;


    extern SharedVar<int> blobmargin;


    extern SharedVar<int> dbgblob;


    extern SharedVar<int> blobstattris;


    extern SharedVar<int> blobdyntris;


    extern SharedVar<int> _numargs;


    extern SharedVar<int> dbgalias;


    extern SharedVar<int> dbgdds;


    extern SharedVar<int> maxcon;


    extern SharedVar<int> confading;


    extern SharedVar<int> fullconsole;


    extern SharedVar<int> consize;


    extern SharedVar<int> miniconsize;


    extern SharedVar<int> miniconwidth;


    extern SharedVar<int> confade;


    extern SharedVar<int> miniconfade;


    extern SharedVar<int> fullconsize;


    extern SharedVar<int> confilter;


    extern SharedVar<int> fullconfilter;


    extern SharedVar<int> miniconfilter;


    extern SharedVar<int> maxhistory;


    extern SharedVar<int> envmapsize;


    extern SharedVar<int> envmapradius;


    extern SharedVar<int> aaenvmap;


    extern SharedVar<int> maxdecaltris;


    extern SharedVar<int> decalfade;


    extern SharedVar<int> dbgdec;


    extern SharedVar<int> showdecals;


    extern SharedVar<int> maxdecaldistance;


    extern SharedVar<int> depthfxfpscale;


    extern SharedVar<int> depthfxscale;


    extern SharedVar<int> depthfxblend;


    extern SharedVar<int> depthfxpartblend;


    extern SharedVar<int> depthfxmargin;


    extern SharedVar<int> depthfxbias;


    extern SharedVar<int> fpdepthfx;


    extern SharedVar<int> depthfxemuprecision;


    extern SharedVar<int> depthfxsize;


    extern SharedVar<int> depthfx;


    extern SharedVar<int> depthfxparts;


    extern SharedVar<int> blurdepthfx;


    extern SharedVar<int> blurdepthfxsigma;


    extern SharedVar<int> depthfxscissor;


    extern SharedVar<int> debugdepthfx;


    extern SharedVar<int> maxdynlights;


    extern SharedVar<int> dynlightdist;


    extern SharedVar<int> rate;


    extern SharedVar<int> throttle_interval;


    extern SharedVar<int> throttle_accel;


    extern SharedVar<int> throttle_decel;


    extern SharedVar<char*> connectname;


    extern SharedVar<int> connectport;


    extern SharedVar<int> fsaa;


    extern SharedVar<char*> background;


    extern SharedVar<char*> logo;


    extern SharedVar<int> userelativemouse;


    extern SharedVar<int> menufps;


    extern SharedVar<int> maxfps;


    extern SharedVar<int> clockerror;


    extern SharedVar<int> clockfix;


    extern SharedVar<int> numcpus;


    extern SharedVar<int> maxclients;


    extern SharedVar<int> maxdupclients;


    extern SharedVar<int> allowupdatemaster;


    extern SharedVar<char*> mastername;


    extern SharedVar<int> masterport;


    extern SharedVar<int> serveruprate;


    extern SharedVar<char*> serverip;


    extern SharedVar<int> serverport;


    extern SharedVar<int> glaresize;


    extern SharedVar<int> glare;


    extern SharedVar<int> blurglare;


    extern SharedVar<int> blurglaresigma;


    extern SharedVar<int> debugglare;


    extern SharedVar<float> glarescale;


    extern SharedVar<int> grass;


    extern SharedVar<int> dbggrass;


    extern SharedVar<int> grassdist;


    extern SharedVar<float> grasstaper;


    extern SharedVar<float> grassstep;


    extern SharedVar<int> grassheight;


    extern SharedVar<int> grassanimmillis;


    extern SharedVar<float> grassanimscale;


    extern SharedVar<int> grassscale;


    extern SharedVar<int> grasscolour;


    extern SharedVar<float> grassalpha;


    extern SharedVar<int> flarelights;


    extern SharedVar<int> flarecutoff;


    extern SharedVar<int> flaresize;


    extern SharedVar<int> lightprecision;


    extern SharedVar<int> lighterror;


    extern SharedVar<int> bumperror;


    extern SharedVar<int> lightlod;


    extern SharedVar<int> ambient;


    extern SharedVar<int> skylight;


    extern SharedVar<int> sunlight;


    extern SharedVar<float> sunlightscale;


    extern SharedVar<int> sunlightyaw;


    extern SharedVar<int> sunlightpitch;


    extern SharedVar<int> skytexturelight;


    extern SharedVar<int> lmshadows_;


    extern SharedVar<int> lmaa_;


    extern SharedVar<int> lerptjoints_;


    extern SharedVar<int> lmao_;


    extern SharedVar<int> lightcompress;


    extern SharedVar<int> ambientocclusion;


    extern SharedVar<float> ambientocclusionradius;


    extern SharedVar<int> debugao;


    extern SharedVar<int> blurlms;


    extern SharedVar<int> blurskylight;


    extern SharedVar<int> edgetolerance;


    extern SharedVar<int> adaptivesample;


    extern SharedVar<int> lightcachesize;


    extern SharedVar<int> lightthreads;


    extern SharedVar<int> patchnormals;


    extern SharedVar<int> fullbright;


    extern SharedVar<int> fullbrightlevel;


    extern SharedVar<int> roundlightmaptex;


    extern SharedVar<int> batchlightmaps;


    extern SharedVar<int> lnjittermillis;


    extern SharedVar<int> lnjitterradius;


    extern SharedVar<float> lnjitterscale;


    extern SharedVar<int> lnscrollmillis;


    extern SharedVar<float> lnscrollscale;


    extern SharedVar<float> lnblendpower;


    extern SharedVar<int> optmats;


    extern SharedVar<int> showmat;


    extern SharedVar<int> glasscolour;


    extern SharedVar<int> glass2colour;


    extern SharedVar<int> glass3colour;


    extern SharedVar<int> glass4colour;


    extern SharedVar<int> glassenv;


    extern SharedVar<int> waterfallenv;


    extern SharedVar<char*> mapdir;


    extern SharedVar<char*> texturedir;


    extern SharedVar<char*> skyboxdir;


    extern SharedVar<char*> interfacedir;


    extern SharedVar<char*> icondir;


    extern SharedVar<char*> sounddir;


    extern SharedVar<char*> musicdir;


    extern SharedVar<int> menudistance;


    extern SharedVar<int> menuautoclose;


    extern SharedVar<int> applydialog;


    extern SharedVar<int> mainmenu;


    extern SharedVar<int> dbgmovie;


    extern SharedVar<int> movieaccelblit;


    extern SharedVar<int> movieaccelyuv;


    extern SharedVar<int> movieaccel;


    extern SharedVar<int> moviesync;


    extern SharedVar<float> movieminquality;


    extern SharedVar<int> moview;


    extern SharedVar<int> movieh;


    extern SharedVar<int> moviefps;


    extern SharedVar<int> moviesound;

namespace ai { 
    extern SharedVar<int> aidebug;
 }
namespace ai { 
    extern SharedVar<int> aiforcegun;
 }
namespace ai { 
    extern SharedVar<int> showwaypoints;
 }
namespace ai { 
    extern SharedVar<int> showwaypointsradius;
 }
namespace ai { 
    extern SharedVar<int> dropwaypoints;
 }
namespace entities { 
    extern SharedVar<int> triggerstate;
 }
namespace game { 
    extern SharedVar<int> minradarscale;
 }
namespace game { 
    extern SharedVar<int> maxradarscale;
 }
namespace game { 
    extern SharedVar<int> radarteammates;
 }
namespace game { 
    extern SharedVar<float> minimapalpha;
 }
namespace game { 
    extern SharedVar<char*> radardir;
 }
namespace game { 
    extern SharedVar<int> capturetether;
 }
namespace game { 
    extern SharedVar<int> autorepammo;
 }
namespace game { 
    extern SharedVar<int> basenumbers;
 }
namespace game { 
    extern SharedVar<int> showbombs;
 }
namespace game { 
    extern SharedVar<int> showbombradius;
 }
namespace game { 
    extern SharedVar<int> showbombdelay;
 }
namespace game { 
    extern SharedVar<int> showminimapobstacles;
 }
namespace game { 
    extern SharedVar<int> deadpush;
 }
namespace game { 
    extern SharedVar<int> autoauth;
 }
namespace game { 
    extern SharedVar<int> smoothmove;
 }
namespace game { 
    extern SharedVar<int> smoothdist;
 }
namespace game { 
    extern SharedVar<int> slowmosp;
 }
namespace game { 
    extern SharedVar<int> spawnwait;
 }
namespace game { 
    extern SharedVar<int> hitsound;
 }
namespace game { 
    extern SharedVar<int> teamcolorfrags;
 }
namespace game { 
    extern SharedVar<int> showmodeinfo;
 }
namespace game { 
    extern SharedVar<int> teamcolortext;
 }
namespace game { 
    extern SharedVar<int> ammohud;
 }
namespace game { 
    extern SharedVar<int> teamcrosshair;
 }
namespace game { 
    extern SharedVar<int> hitcrosshair;
 }
namespace game { 
    extern SharedVar<int> skill;
 }
namespace game { 
    extern SharedVar<int> killsendsp;
 }
namespace game { 
    extern SharedVar<int> ragdoll;
 }
namespace game { 
    extern SharedVar<int> ragdollmillis;
 }
namespace game { 
    extern SharedVar<int> ragdollfade;
 }
namespace game { 
    extern SharedVar<int> forceplayermodels;
 }
namespace game { 
    extern SharedVar<int> hidedead;
 }
namespace game { 
    extern SharedVar<int> testquad;
 }
namespace game { 
    extern SharedVar<int> testarmour;
 }
namespace game { 
    extern SharedVar<int> hudgun;
 }
namespace game { 
    extern SharedVar<int> hudgunsway;
 }
namespace game { 
    extern SharedVar<int> teamhudguns;
 }
namespace game { 
    extern SharedVar<int> chainsawhudgun;
 }
namespace game { 
    extern SharedVar<int> testhudgun;
 }
namespace game { 
    extern SharedVar<float> swaystep;
 }
namespace game { 
    extern SharedVar<float> swayside;
 }
namespace game { 
    extern SharedVar<float> swayup;
 }
namespace game { 
    extern SharedVar<char*> hudgunsdir;
 }
namespace game { 
    extern SharedVar<int> scoreboard2d;
 }
namespace game { 
    extern SharedVar<int> showservinfo;
 }
namespace game { 
    extern SharedVar<int> showclientnum;
 }
namespace game { 
    extern SharedVar<int> showpj;
 }
namespace game { 
    extern SharedVar<int> showping;
 }
namespace game { 
    extern SharedVar<int> showspectators;
 }
namespace game { 
    extern SharedVar<int> showflags;
 }
namespace game { 
    extern SharedVar<int> showfrags;
 }
namespace game { 
    extern SharedVar<int> showaccuracy;
 }
namespace game { 
    extern SharedVar<int> highlightscore;
 }
namespace game { 
    extern SharedVar<int> showconnecting;
 }
namespace game { 
    extern SharedVar<int> showscoreboard;
 }
namespace game { 
    extern SharedVar<int> maxdebris;
 }
namespace game { 
    extern SharedVar<int> maxbarreldebris;
 }
namespace game { 
    extern SharedVar<int> blood;
 }
namespace game { 
    extern SharedVar<int> muzzleflash;
 }
namespace game { 
    extern SharedVar<int> muzzlelight;
 }
namespace game { 
    extern SharedVar<int> bombcolliderad;
 }
namespace game { 
    extern SharedVar<int> bombbarrier;
 }
namespace game { 
    extern SharedVar<int> deathscore;
 }
namespace game { 
    extern SharedVar<int> playermodel;
 }
namespace game { 
    extern SharedVar<int> testteam;
 }
namespace game { 
    extern SharedVar<int> teamskins;
 }
namespace inexor { namespace rendering { namespace screen { 
    extern SharedVar<int> scr_w;
 } } }
namespace inexor { namespace rendering { namespace screen { 
    extern SharedVar<int> scr_h;
 } } }
namespace inexor { namespace rendering { namespace screen { 
    extern SharedVar<int> colorbits;
 } } }
namespace inexor { namespace rendering { namespace screen { 
    extern SharedVar<int> depthbits;
 } } }
namespace inexor { namespace rendering { namespace screen { 
    extern SharedVar<int> stencilbits;
 } } }
namespace inexor { namespace rendering { namespace screen { 
    extern SharedVar<int> gamma;
 } } }
namespace inexor { namespace rendering { namespace screen { 
    extern SharedVar<int> vsync;
 } } }
namespace inexor { namespace rendering { namespace screen { 
    extern SharedVar<int> vsynctear;
 } } }
namespace inexor { namespace rendering { namespace screen { 
    extern SharedVar<int> fullscreen;
 } } }
namespace inexor { namespace sound { 
    extern SharedVar<int> soundvol;
 } }
namespace inexor { namespace sound { 
    extern SharedVar<int> musicvol;
 } }
namespace inexor { namespace sound { 
    extern SharedVar<int> stereo;
 } }
namespace inexor { namespace sound { 
    extern SharedVar<int> maxsoundradius;
 } }
namespace inexor { namespace sound { 
    extern SharedVar<int> maxsoundsatonce;
 } }
namespace inexor { namespace sound { 
    extern SharedVar<int> dbgsound;
 } }
namespace inexor { namespace sound { 
    extern SharedVar<int> mumble;
 } }
namespace inexor { namespace sound { 
    extern SharedVar<int> soundchans;
 } }
namespace inexor { namespace sound { 
    extern SharedVar<int> soundfreq;
 } }
namespace inexor { namespace sound { 
    extern SharedVar<int> soundbufferlen;
 } }
namespace server { 
    extern SharedVar<int> lockmaprotation;
 }
namespace server { 
    extern SharedVar<int> maxdemos;
 }
namespace server { 
    extern SharedVar<int> maxdemosize;
 }
namespace server { 
    extern SharedVar<int> restrictdemos;
 }
namespace server { 
    extern SharedVar<int> restrictpausegame;
 }
namespace server { 
    extern SharedVar<int> restrictgamespeed;
 }
namespace server { 
    extern SharedVar<int> restrictpersistteams;
 }
namespace server { 
    extern SharedVar<char*> serverdesc;
 }
namespace server { 
    extern SharedVar<char*> serverpass;
 }
namespace server { 
    extern SharedVar<char*> adminpass;
 }
namespace server { 
    extern SharedVar<int> publicserver;
 }
namespace server { 
    extern SharedVar<char*> servermotd;
 }
namespace server { 
    extern SharedVar<int> spectatemodifiedmap;
 }
namespace server { 
    extern SharedVar<int> ctftkpenalty;
 }
namespace server { 
    extern SharedVar<char*> serverauth;
 }
namespace server { 
    extern SharedVar<int> modifiedmapspectator;
 }
namespace server { 
    extern SharedVar<int> extinfoip;
 }
namespace server { namespace aiman { 
    extern SharedVar<int> botlimit;
 } }
namespace server { namespace aiman { 
    extern SharedVar<int> serverbotbalance;
 } }

    extern SharedVar<int> lerpangle;


    extern SharedVar<int> lerpsubdiv;


    extern SharedVar<int> lerpsubdivsize;


    extern SharedVar<int> dragging;


    extern SharedVar<int> gridpower;


    extern SharedVar<int> passthroughsel;


    extern SharedVar<int> editing;


    extern SharedVar<int> selectcorners;


    extern SharedVar<int> hmapedit;


    extern SharedVar<int> gridlookup;


    extern SharedVar<int> passthroughcube;


    extern SharedVar<int> undomegs;


    extern SharedVar<int> nompedit;


    extern SharedVar<char*> prefabdir;


    extern SharedVar<int> brushx;


    extern SharedVar<int> brushy;


    extern SharedVar<int> invalidcubeguard;


    extern SharedVar<int> selectionsurf;


    extern SharedVar<int> usevdelta;


    extern SharedVar<int> allfaces;


    extern SharedVar<int> texguiwidth;


    extern SharedVar<int> texguiheight;


    extern SharedVar<int> texguitime;


    extern SharedVar<int> texgui2d;


    extern SharedVar<int> debugvbo;


    extern SharedVar<int> maxvbosize;


    extern SharedVar<int> filltjoints;


    extern SharedVar<int> vafacemax;


    extern SharedVar<int> vafacemin;


    extern SharedVar<int> vacubesize;


    extern SharedVar<int> mipvis;


    extern SharedVar<int> maxmerge;


    extern SharedVar<int> minface;


    extern SharedVar<int> dynentsize;


    extern SharedVar<int> maxroll;


    extern SharedVar<float> straferoll;


    extern SharedVar<float> faderoll;


    extern SharedVar<int> floatspeed;


    extern SharedVar<int> physinterp;


    extern SharedVar<int> maxpvsblocker;


    extern SharedVar<int> pvsleafsize;


    extern SharedVar<int> pvsthreads;


    extern SharedVar<int> lockpvs;


    extern SharedVar<int> usepvs;


    extern SharedVar<int> usewaterpvs;


    extern SharedVar<int> ragdolltimestepmin;


    extern SharedVar<int> ragdolltimestepmax;


    extern SharedVar<float> ragdollrotfric;


    extern SharedVar<float> ragdollrotfricstop;


    extern SharedVar<int> ragdollconstrain;


    extern SharedVar<float> ragdollbodyfric;


    extern SharedVar<float> ragdollbodyfricscale;


    extern SharedVar<float> ragdollwaterfric;


    extern SharedVar<float> ragdollgroundfric;


    extern SharedVar<float> ragdollairfric;


    extern SharedVar<float> ragdollunstick;


    extern SharedVar<int> ragdollexpireoffset;


    extern SharedVar<int> ragdollwaterexpireoffset;


    extern SharedVar<float> ragdolleyesmooth;


    extern SharedVar<int> ragdolleyesmoothmillis;


    extern SharedVar<int> glversion;


    extern SharedVar<int> glslversion;


    extern SharedVar<int> ati_skybox_bug;


    extern SharedVar<int> ati_minmax_bug;


    extern SharedVar<int> ati_cubemap_bug;


    extern SharedVar<int> intel_vertexarray_bug;


    extern SharedVar<int> intel_mapbufferrange_bug;


    extern SharedVar<int> minimizetcusage;


    extern SharedVar<int> useubo;


    extern SharedVar<int> usetexcompress;


    extern SharedVar<int> rtscissor;


    extern SharedVar<int> blurtile;


    extern SharedVar<int> rtsharefb;


    extern SharedVar<int> dbgexts;


    extern SharedVar<int> wireframe;


    extern SharedVar<int> zoominvel;


    extern SharedVar<int> zoomoutvel;


    extern SharedVar<int> zoomfov;


    extern SharedVar<int> fov;


    extern SharedVar<int> followfov;


    extern SharedVar<int> avatarzoomfov;


    extern SharedVar<int> avatarfov;


    extern SharedVar<float> avatardepth;


    extern SharedVar<float> forceaspect;


    extern SharedVar<int> zoom;


    extern SharedVar<float> zoomsens;


    extern SharedVar<float> zoomaccel;


    extern SharedVar<int> zoomautosens;


    extern SharedVar<float> sensitivity;


    extern SharedVar<float> sensitivityscale;


    extern SharedVar<int> invmouse;


    extern SharedVar<float> mouseaccel;


    extern SharedVar<int> thirdperson;


    extern SharedVar<float> thirdpersondistance;


    extern SharedVar<float> thirdpersonup;


    extern SharedVar<float> thirdpersonside;


    extern SharedVar<float> nearplane;


    extern SharedVar<int> reflectclip;


    extern SharedVar<int> reflectclipavatar;


    extern SharedVar<float> polygonoffsetfactor;


    extern SharedVar<float> polygonoffsetunits;


    extern SharedVar<float> depthoffset;


    extern SharedVar<int> fog;


    extern SharedVar<int> fogcolour;


    extern SharedVar<int> skyboxglare;


    extern SharedVar<int> reflectmms;


    extern SharedVar<int> refractsky;


    extern SharedVar<int> modelpreviewfov;


    extern SharedVar<int> modelpreviewpitch;


    extern SharedVar<int> minimapheight;


    extern SharedVar<int> minimapcolour;


    extern SharedVar<int> minimapclip;


    extern SharedVar<int> minimapsize;


    extern SharedVar<int> motionblur;


    extern SharedVar<int> motionblurmillis;


    extern SharedVar<float> motionblurscale;


    extern SharedVar<int> usedamagecompass;


    extern SharedVar<int> damagecompassfade;


    extern SharedVar<int> damagecompasssize;


    extern SharedVar<int> damagecompassalpha;


    extern SharedVar<int> damagecompassmin;


    extern SharedVar<int> damagecompassmax;


    extern SharedVar<int> damagescreen;


    extern SharedVar<int> damagescreenfactor;


    extern SharedVar<int> damagescreenalpha;


    extern SharedVar<int> damagescreenfade;


    extern SharedVar<int> damagescreenmin;


    extern SharedVar<int> damagescreenmax;


    extern SharedVar<int> hidestats;


    extern SharedVar<int> hidehud;


    extern SharedVar<int> crosshairsize;


    extern SharedVar<int> cursorsize;


    extern SharedVar<int> crosshairfx;


    extern SharedVar<int> crosshaircolors;


    extern SharedVar<char*> crosshairdir;


    extern SharedVar<char*> cursor;


    extern SharedVar<int> wallclock;


    extern SharedVar<int> wallclock24;


    extern SharedVar<int> wallclocksecs;


    extern SharedVar<int> showfps;


    extern SharedVar<int> showfpsrange;


    extern SharedVar<int> showeditstats;


    extern SharedVar<int> statrate;


    extern SharedVar<float> conscale;


    extern SharedVar<char*> modeldir;


    extern SharedVar<int> oqdynent;


    extern SharedVar<int> animationinterpolationtime;


    extern SharedVar<int> showboundingbox;


    extern SharedVar<int> maxmodelradiusdistance;


    extern SharedVar<int> animoverride;


    extern SharedVar<int> testanims;


    extern SharedVar<int> testpitch;


    extern SharedVar<int> particlesize;


    extern SharedVar<int> emitmillis;


    extern SharedVar<int> showparticles;


    extern SharedVar<int> cullparticles;


    extern SharedVar<int> replayparticles;


    extern SharedVar<int> seedmillis;


    extern SharedVar<int> dbgpcull;


    extern SharedVar<int> dbgpseed;


    extern SharedVar<int> outlinemeters;


    extern SharedVar<int> maxparticles;


    extern SharedVar<int> fewparticles;


    extern SharedVar<int> particleglare;


    extern SharedVar<int> dbgparts;


    extern SharedVar<int> maxparticledistance;


    extern SharedVar<int> maxtrail;


    extern SharedVar<int> particletext;


    extern SharedVar<int> maxparticletextdistance;


    extern SharedVar<char*> skybox;


    extern SharedVar<int> skyboxcolour;


    extern SharedVar<float> spinsky;


    extern SharedVar<int> yawsky;


    extern SharedVar<char*> cloudbox;


    extern SharedVar<int> cloudboxcolour;


    extern SharedVar<float> cloudboxalpha;


    extern SharedVar<float> spinclouds;


    extern SharedVar<int> yawclouds;


    extern SharedVar<float> cloudclip;


    extern SharedVar<char*> cloudlayer;


    extern SharedVar<float> cloudoffsetx;


    extern SharedVar<float> cloudoffsety;


    extern SharedVar<float> cloudscrollx;


    extern SharedVar<float> cloudscrolly;


    extern SharedVar<float> cloudscale;


    extern SharedVar<float> spincloudlayer;


    extern SharedVar<int> yawcloudlayer;


    extern SharedVar<float> cloudheight;


    extern SharedVar<float> cloudfade;


    extern SharedVar<float> cloudalpha;


    extern SharedVar<int> cloudsubdiv;


    extern SharedVar<int> cloudcolour;


    extern SharedVar<float> fogdomeheight;


    extern SharedVar<float> fogdomemin;


    extern SharedVar<float> fogdomemax;


    extern SharedVar<int> fogdomecap;


    extern SharedVar<float> fogdomeclip;


    extern SharedVar<int> fogdomecolour;


    extern SharedVar<int> sparklyfix;


    extern SharedVar<int> showsky;


    extern SharedVar<int> clipsky;


    extern SharedVar<int> clampsky;


    extern SharedVar<int> fogdomeclouds;


    extern SharedVar<int> useskytexture;


    extern SharedVar<int> oqfrags;


    extern SharedVar<int> oqwait;


    extern SharedVar<int> oqmm;


    extern SharedVar<int> outline;


    extern SharedVar<int> outlinecolour;


    extern SharedVar<int> dtoutline;


    extern SharedVar<int> blendbrushcolor;


    extern SharedVar<int> oqdist;


    extern SharedVar<int> zpass;


    extern SharedVar<int> glowpass;


    extern SharedVar<int> envpass;


    extern SharedVar<int> batchgeom;


    extern SharedVar<char*> causticdir;


    extern SharedVar<int> causticscale;


    extern SharedVar<int> causticmillis;


    extern SharedVar<int> caustics;


    extern SharedVar<int> oqgeom;


    extern SharedVar<int> compresspng;


    extern SharedVar<int> compresstga;


    extern SharedVar<char*> screenshotdir;


    extern SharedVar<int> screenshotformat;


    extern SharedVar<int> searchlan;


    extern SharedVar<int> servpingrate;


    extern SharedVar<int> servpingdecay;


    extern SharedVar<int> maxservpings;


    extern SharedVar<int> autosortservers;


    extern SharedVar<int> autoupdateservers;


    extern SharedVar<int> reservevpparams;


    extern SharedVar<int> maxvsuniforms;


    extern SharedVar<int> maxfsuniforms;


    extern SharedVar<int> maxvaryings;


    extern SharedVar<int> dbgshader;


    extern SharedVar<int> dbgubo;


    extern SharedVar<int> shaderprecision;


    extern SharedVar<int> defershaders;


    extern SharedVar<int> shaderdetail;


    extern SharedVar<int> shadowmap;


    extern SharedVar<int> shadowmapsize;


    extern SharedVar<int> shadowmapradius;


    extern SharedVar<int> shadowmapheight;


    extern SharedVar<int> shadowmapdist;


    extern SharedVar<int> fpshadowmap;


    extern SharedVar<int> shadowmapprecision;


    extern SharedVar<int> shadowmapambient;


    extern SharedVar<int> shadowmapintensity;


    extern SharedVar<int> blurshadowmap;


    extern SharedVar<int> blursmsigma;


    extern SharedVar<int> shadowmapcasters;


    extern SharedVar<int> shadowmapangle;


    extern SharedVar<int> shadowmapbias;


    extern SharedVar<int> shadowmappeelbias;


    extern SharedVar<int> smdepthpeel;


    extern SharedVar<int> smoothshadowmappeel;


    extern SharedVar<int> debugsm;


    extern SharedVar<int> gpuskel;


    extern SharedVar<int> maxskelanimdata;


    extern SharedVar<int> testtags;


    extern SharedVar<int> autocompactvslots;


    extern SharedVar<int> dbggz;


    extern SharedVar<int> hwtexsize;


    extern SharedVar<int> hwcubetexsize;


    extern SharedVar<int> hwmaxaniso;


    extern SharedVar<int> maxtexsize;


    extern SharedVar<int> reducefilter;


    extern SharedVar<int> texreduce;


    extern SharedVar<int> trilinear;


    extern SharedVar<int> bilinear;


    extern SharedVar<int> aniso;


    extern SharedVar<int> texcompress;


    extern SharedVar<int> texcompressquality;


    extern SharedVar<int> usenp2;


    extern SharedVar<int> usedds;


    extern SharedVar<int> scaledds;


    extern SharedVar<int> waterreflect;


    extern SharedVar<int> waterrefract;


    extern SharedVar<int> waterenvmap;


    extern SharedVar<int> waterfallrefract;


    extern SharedVar<int> watersubdiv;


    extern SharedVar<int> waterlod;


    extern SharedVar<int> vertwater;


    extern SharedVar<int> reflectdist;


    extern SharedVar<int> watercolour;


    extern SharedVar<int> waterfog;


    extern SharedVar<int> waterspec;


    extern SharedVar<int> waterfallcolour;


    extern SharedVar<int> water2colour;


    extern SharedVar<int> water2fog;


    extern SharedVar<int> water2spec;


    extern SharedVar<int> water2fallcolour;


    extern SharedVar<int> water3colour;


    extern SharedVar<int> water3fog;


    extern SharedVar<int> water3spec;


    extern SharedVar<int> water3fallcolour;


    extern SharedVar<int> water4colour;


    extern SharedVar<int> water4fog;


    extern SharedVar<int> water4spec;


    extern SharedVar<int> water4fallcolour;


    extern SharedVar<int> lavacolour;


    extern SharedVar<int> lavafog;


    extern SharedVar<int> lava2colour;


    extern SharedVar<int> lava2fog;


    extern SharedVar<int> lava3colour;


    extern SharedVar<int> lava3fog;


    extern SharedVar<int> lava4colour;


    extern SharedVar<int> lava4fog;


    extern SharedVar<int> oqwater;


    extern SharedVar<int> waterfade;


    extern SharedVar<int> reflectsize;


    extern SharedVar<int> maxreflect;


    extern SharedVar<int> maskreflect;


    extern SharedVar<int> reflectscissor;


    extern SharedVar<int> reflectvfc;


    extern SharedVar<int> refractclear;


    extern SharedVar<int> savebak;


    extern SharedVar<int> dbgvars;


    extern SharedVar<int> mapversion;


    extern SharedVar<int> worldscale;


    extern SharedVar<int> worldsize;


    extern SharedVar<char*> maptitle;


    extern SharedVar<int> octaentsize;


    extern SharedVar<int> entselradius;


    extern SharedVar<int> entediting;


    extern SharedVar<int> attachradius;


    extern SharedVar<int> entselsnap;


    extern SharedVar<int> entmovingshadow;


    extern SharedVar<int> showentradius;


    extern SharedVar<int> entitysurf;


    extern SharedVar<int> entautoviewdist;


    extern SharedVar<int> entdrop;


    extern SharedVar<int> dbgzip;



namespace inexor { namespace rpc {

/// Known C++ SharedVar types
enum cpp_type_t
{
    t_cstring = 0,
    t_float,
    t_int
};

class treedata {
  public:

    void connectall()
    {
        // TODO: Dont call by type but by reference if not a ptr: *or& -> {cpp_observer_type}
        guiautotab.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_guiautotab(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        guiclicktab.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_guiclicktab(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        guifadein.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_guifadein(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        guipushdist.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_guipushdist(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        guisens.onChange.connect([](const float oldvalue, const float newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_guisens(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        useguifollow.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_useguifollow(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        usegui2d.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_usegui2d(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        envmapmodels.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_envmapmodels(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        bumpmodels.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_bumpmodels(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        fullbrightmodels.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_fullbrightmodels(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        blendpaintmode.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_blendpaintmode(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        paintblendmapdelay.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_paintblendmapdelay(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        paintblendmapinterval.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_paintblendmapinterval(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        showblobs.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_showblobs(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        blobintensity.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_blobintensity(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        blobheight.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_blobheight(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        blobfadelow.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_blobfadelow(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        blobfadehigh.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_blobfadehigh(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        blobmargin.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_blobmargin(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        dbgblob.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_dbgblob(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        blobstattris.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_blobstattris(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        blobdyntris.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_blobdyntris(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        _numargs.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set__numargs(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        dbgalias.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_dbgalias(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        dbgdds.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_dbgdds(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        maxcon.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_maxcon(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        confading.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_confading(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        fullconsole.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_fullconsole(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        consize.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_consize(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        miniconsize.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_miniconsize(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        miniconwidth.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_miniconwidth(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        confade.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_confade(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        miniconfade.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_miniconfade(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        fullconsize.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_fullconsize(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        confilter.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_confilter(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        fullconfilter.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_fullconfilter(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        miniconfilter.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_miniconfilter(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        maxhistory.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_maxhistory(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        envmapsize.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_envmapsize(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        envmapradius.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_envmapradius(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        aaenvmap.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_aaenvmap(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        maxdecaltris.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_maxdecaltris(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        decalfade.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_decalfade(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        dbgdec.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_dbgdec(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        showdecals.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_showdecals(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        maxdecaldistance.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_maxdecaldistance(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        depthfxfpscale.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_depthfxfpscale(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        depthfxscale.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_depthfxscale(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        depthfxblend.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_depthfxblend(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        depthfxpartblend.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_depthfxpartblend(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        depthfxmargin.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_depthfxmargin(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        depthfxbias.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_depthfxbias(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        fpdepthfx.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_fpdepthfx(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        depthfxemuprecision.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_depthfxemuprecision(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        depthfxsize.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_depthfxsize(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        depthfx.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_depthfx(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        depthfxparts.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_depthfxparts(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        blurdepthfx.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_blurdepthfx(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        blurdepthfxsigma.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_blurdepthfxsigma(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        depthfxscissor.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_depthfxscissor(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        debugdepthfx.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_debugdepthfx(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        maxdynlights.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_maxdynlights(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        dynlightdist.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_dynlightdist(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        rate.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_rate(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        throttle_interval.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_throttle_interval(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        throttle_accel.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_throttle_accel(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        throttle_decel.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_throttle_decel(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        connectname.onChange.connect([](const char* oldvalue, const char* newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_connectname(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        connectport.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_connectport(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        fsaa.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_fsaa(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        background.onChange.connect([](const char* oldvalue, const char* newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_background(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        logo.onChange.connect([](const char* oldvalue, const char* newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_logo(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        userelativemouse.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_userelativemouse(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        menufps.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_menufps(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        maxfps.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_maxfps(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        clockerror.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_clockerror(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        clockfix.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_clockfix(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        numcpus.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_numcpus(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        maxclients.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_maxclients(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        maxdupclients.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_maxdupclients(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        allowupdatemaster.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_allowupdatemaster(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        mastername.onChange.connect([](const char* oldvalue, const char* newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_mastername(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        masterport.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_masterport(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        serveruprate.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_serveruprate(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        serverip.onChange.connect([](const char* oldvalue, const char* newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_serverip(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        serverport.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_serverport(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        glaresize.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_glaresize(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        glare.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_glare(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        blurglare.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_blurglare(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        blurglaresigma.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_blurglaresigma(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        debugglare.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_debugglare(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        glarescale.onChange.connect([](const float oldvalue, const float newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_glarescale(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        grass.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_grass(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        dbggrass.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_dbggrass(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        grassdist.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_grassdist(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        grasstaper.onChange.connect([](const float oldvalue, const float newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_grasstaper(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        grassstep.onChange.connect([](const float oldvalue, const float newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_grassstep(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        grassheight.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_grassheight(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        grassanimmillis.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_grassanimmillis(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        grassanimscale.onChange.connect([](const float oldvalue, const float newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_grassanimscale(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        grassscale.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_grassscale(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        grasscolour.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_grasscolour(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        grassalpha.onChange.connect([](const float oldvalue, const float newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_grassalpha(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        flarelights.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_flarelights(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        flarecutoff.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_flarecutoff(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        flaresize.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_flaresize(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        lightprecision.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_lightprecision(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        lighterror.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_lighterror(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        bumperror.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_bumperror(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        lightlod.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_lightlod(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        ambient.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_ambient(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        skylight.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_skylight(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        sunlight.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_sunlight(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        sunlightscale.onChange.connect([](const float oldvalue, const float newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_sunlightscale(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        sunlightyaw.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_sunlightyaw(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        sunlightpitch.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_sunlightpitch(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        skytexturelight.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_skytexturelight(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        lmshadows_.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_lmshadows_(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        lmaa_.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_lmaa_(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        lerptjoints_.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_lerptjoints_(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        lmao_.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_lmao_(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        lightcompress.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_lightcompress(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        ambientocclusion.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_ambientocclusion(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        ambientocclusionradius.onChange.connect([](const float oldvalue, const float newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_ambientocclusionradius(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        debugao.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_debugao(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        blurlms.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_blurlms(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        blurskylight.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_blurskylight(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        edgetolerance.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_edgetolerance(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        adaptivesample.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_adaptivesample(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        lightcachesize.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_lightcachesize(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        lightthreads.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_lightthreads(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        patchnormals.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_patchnormals(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        fullbright.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_fullbright(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        fullbrightlevel.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_fullbrightlevel(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        roundlightmaptex.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_roundlightmaptex(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        batchlightmaps.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_batchlightmaps(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        lnjittermillis.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_lnjittermillis(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        lnjitterradius.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_lnjitterradius(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        lnjitterscale.onChange.connect([](const float oldvalue, const float newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_lnjitterscale(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        lnscrollmillis.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_lnscrollmillis(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        lnscrollscale.onChange.connect([](const float oldvalue, const float newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_lnscrollscale(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        lnblendpower.onChange.connect([](const float oldvalue, const float newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_lnblendpower(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        optmats.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_optmats(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        showmat.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_showmat(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        glasscolour.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_glasscolour(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        glass2colour.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_glass2colour(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        glass3colour.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_glass3colour(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        glass4colour.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_glass4colour(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        glassenv.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_glassenv(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        waterfallenv.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_waterfallenv(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        mapdir.onChange.connect([](const char* oldvalue, const char* newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_mapdir(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        texturedir.onChange.connect([](const char* oldvalue, const char* newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_texturedir(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        skyboxdir.onChange.connect([](const char* oldvalue, const char* newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_skyboxdir(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        interfacedir.onChange.connect([](const char* oldvalue, const char* newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_interfacedir(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        icondir.onChange.connect([](const char* oldvalue, const char* newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_icondir(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        sounddir.onChange.connect([](const char* oldvalue, const char* newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_sounddir(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        musicdir.onChange.connect([](const char* oldvalue, const char* newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_musicdir(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        menudistance.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_menudistance(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        menuautoclose.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_menuautoclose(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        applydialog.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_applydialog(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        mainmenu.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_mainmenu(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        dbgmovie.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_dbgmovie(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        movieaccelblit.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_movieaccelblit(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        movieaccelyuv.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_movieaccelyuv(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        movieaccel.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_movieaccel(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        moviesync.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_moviesync(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        movieminquality.onChange.connect([](const float oldvalue, const float newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_movieminquality(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        moview.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_moview(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        movieh.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_movieh(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        moviefps.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_moviefps(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        moviesound.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_moviesound(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        ai::aidebug.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_ai_aidebug(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        ai::aiforcegun.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_ai_aiforcegun(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        ai::showwaypoints.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_ai_showwaypoints(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        ai::showwaypointsradius.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_ai_showwaypointsradius(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        ai::dropwaypoints.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_ai_dropwaypoints(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        entities::triggerstate.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_entities_triggerstate(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        game::minradarscale.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_game_minradarscale(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        game::maxradarscale.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_game_maxradarscale(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        game::radarteammates.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_game_radarteammates(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        game::minimapalpha.onChange.connect([](const float oldvalue, const float newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_game_minimapalpha(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        game::radardir.onChange.connect([](const char* oldvalue, const char* newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_game_radardir(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        game::capturetether.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_game_capturetether(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        game::autorepammo.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_game_autorepammo(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        game::basenumbers.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_game_basenumbers(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        game::showbombs.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_game_showbombs(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        game::showbombradius.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_game_showbombradius(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        game::showbombdelay.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_game_showbombdelay(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        game::showminimapobstacles.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_game_showminimapobstacles(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        game::deadpush.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_game_deadpush(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        game::autoauth.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_game_autoauth(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        game::smoothmove.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_game_smoothmove(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        game::smoothdist.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_game_smoothdist(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        game::slowmosp.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_game_slowmosp(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        game::spawnwait.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_game_spawnwait(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        game::hitsound.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_game_hitsound(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        game::teamcolorfrags.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_game_teamcolorfrags(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        game::showmodeinfo.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_game_showmodeinfo(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        game::teamcolortext.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_game_teamcolortext(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        game::ammohud.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_game_ammohud(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        game::teamcrosshair.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_game_teamcrosshair(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        game::hitcrosshair.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_game_hitcrosshair(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        game::skill.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_game_skill(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        game::killsendsp.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_game_killsendsp(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        game::ragdoll.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_game_ragdoll(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        game::ragdollmillis.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_game_ragdollmillis(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        game::ragdollfade.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_game_ragdollfade(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        game::forceplayermodels.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_game_forceplayermodels(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        game::hidedead.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_game_hidedead(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        game::testquad.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_game_testquad(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        game::testarmour.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_game_testarmour(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        game::hudgun.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_game_hudgun(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        game::hudgunsway.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_game_hudgunsway(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        game::teamhudguns.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_game_teamhudguns(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        game::chainsawhudgun.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_game_chainsawhudgun(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        game::testhudgun.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_game_testhudgun(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        game::swaystep.onChange.connect([](const float oldvalue, const float newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_game_swaystep(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        game::swayside.onChange.connect([](const float oldvalue, const float newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_game_swayside(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        game::swayup.onChange.connect([](const float oldvalue, const float newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_game_swayup(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        game::hudgunsdir.onChange.connect([](const char* oldvalue, const char* newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_game_hudgunsdir(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        game::scoreboard2d.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_game_scoreboard2d(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        game::showservinfo.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_game_showservinfo(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        game::showclientnum.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_game_showclientnum(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        game::showpj.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_game_showpj(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        game::showping.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_game_showping(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        game::showspectators.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_game_showspectators(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        game::showflags.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_game_showflags(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        game::showfrags.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_game_showfrags(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        game::showaccuracy.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_game_showaccuracy(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        game::highlightscore.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_game_highlightscore(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        game::showconnecting.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_game_showconnecting(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        game::showscoreboard.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_game_showscoreboard(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        game::maxdebris.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_game_maxdebris(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        game::maxbarreldebris.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_game_maxbarreldebris(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        game::blood.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_game_blood(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        game::muzzleflash.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_game_muzzleflash(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        game::muzzlelight.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_game_muzzlelight(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        game::bombcolliderad.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_game_bombcolliderad(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        game::bombbarrier.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_game_bombbarrier(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        game::deathscore.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_game_deathscore(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        game::playermodel.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_game_playermodel(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        game::testteam.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_game_testteam(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        game::teamskins.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_game_teamskins(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        inexor::rendering::screen::scr_w.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_inexor_rendering_screen_scr_w(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        inexor::rendering::screen::scr_h.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_inexor_rendering_screen_scr_h(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        inexor::rendering::screen::colorbits.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_inexor_rendering_screen_colorbits(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        inexor::rendering::screen::depthbits.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_inexor_rendering_screen_depthbits(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        inexor::rendering::screen::stencilbits.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_inexor_rendering_screen_stencilbits(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        inexor::rendering::screen::gamma.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_inexor_rendering_screen_gamma(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        inexor::rendering::screen::vsync.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_inexor_rendering_screen_vsync(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        inexor::rendering::screen::vsynctear.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_inexor_rendering_screen_vsynctear(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        inexor::rendering::screen::fullscreen.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_inexor_rendering_screen_fullscreen(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        inexor::sound::soundvol.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_inexor_sound_soundvol(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        inexor::sound::musicvol.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_inexor_sound_musicvol(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        inexor::sound::stereo.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_inexor_sound_stereo(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        inexor::sound::maxsoundradius.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_inexor_sound_maxsoundradius(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        inexor::sound::maxsoundsatonce.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_inexor_sound_maxsoundsatonce(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        inexor::sound::dbgsound.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_inexor_sound_dbgsound(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        inexor::sound::mumble.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_inexor_sound_mumble(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        inexor::sound::soundchans.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_inexor_sound_soundchans(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        inexor::sound::soundfreq.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_inexor_sound_soundfreq(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        inexor::sound::soundbufferlen.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_inexor_sound_soundbufferlen(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        server::lockmaprotation.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_server_lockmaprotation(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        server::maxdemos.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_server_maxdemos(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        server::maxdemosize.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_server_maxdemosize(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        server::restrictdemos.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_server_restrictdemos(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        server::restrictpausegame.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_server_restrictpausegame(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        server::restrictgamespeed.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_server_restrictgamespeed(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        server::restrictpersistteams.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_server_restrictpersistteams(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        server::serverdesc.onChange.connect([](const char* oldvalue, const char* newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_server_serverdesc(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        server::serverpass.onChange.connect([](const char* oldvalue, const char* newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_server_serverpass(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        server::adminpass.onChange.connect([](const char* oldvalue, const char* newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_server_adminpass(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        server::publicserver.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_server_publicserver(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        server::servermotd.onChange.connect([](const char* oldvalue, const char* newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_server_servermotd(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        server::spectatemodifiedmap.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_server_spectatemodifiedmap(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        server::ctftkpenalty.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_server_ctftkpenalty(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        server::serverauth.onChange.connect([](const char* oldvalue, const char* newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_server_serverauth(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        server::modifiedmapspectator.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_server_modifiedmapspectator(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        server::extinfoip.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_server_extinfoip(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        server::aiman::botlimit.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_server_aiman_botlimit(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        server::aiman::serverbotbalance.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_server_aiman_serverbotbalance(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        lerpangle.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_lerpangle(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        lerpsubdiv.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_lerpsubdiv(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        lerpsubdivsize.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_lerpsubdivsize(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        dragging.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_dragging(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        gridpower.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_gridpower(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        passthroughsel.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_passthroughsel(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        editing.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_editing(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        selectcorners.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_selectcorners(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        hmapedit.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_hmapedit(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        gridlookup.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_gridlookup(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        passthroughcube.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_passthroughcube(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        undomegs.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_undomegs(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        nompedit.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_nompedit(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        prefabdir.onChange.connect([](const char* oldvalue, const char* newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_prefabdir(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        brushx.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_brushx(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        brushy.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_brushy(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        invalidcubeguard.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_invalidcubeguard(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        selectionsurf.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_selectionsurf(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        usevdelta.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_usevdelta(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        allfaces.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_allfaces(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        texguiwidth.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_texguiwidth(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        texguiheight.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_texguiheight(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        texguitime.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_texguitime(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        texgui2d.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_texgui2d(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        debugvbo.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_debugvbo(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        maxvbosize.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_maxvbosize(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        filltjoints.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_filltjoints(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        vafacemax.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_vafacemax(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        vafacemin.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_vafacemin(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        vacubesize.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_vacubesize(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        mipvis.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_mipvis(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        maxmerge.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_maxmerge(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        minface.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_minface(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        dynentsize.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_dynentsize(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        maxroll.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_maxroll(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        straferoll.onChange.connect([](const float oldvalue, const float newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_straferoll(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        faderoll.onChange.connect([](const float oldvalue, const float newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_faderoll(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        floatspeed.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_floatspeed(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        physinterp.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_physinterp(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        maxpvsblocker.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_maxpvsblocker(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        pvsleafsize.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_pvsleafsize(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        pvsthreads.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_pvsthreads(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        lockpvs.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_lockpvs(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        usepvs.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_usepvs(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        usewaterpvs.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_usewaterpvs(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        ragdolltimestepmin.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_ragdolltimestepmin(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        ragdolltimestepmax.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_ragdolltimestepmax(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        ragdollrotfric.onChange.connect([](const float oldvalue, const float newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_ragdollrotfric(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        ragdollrotfricstop.onChange.connect([](const float oldvalue, const float newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_ragdollrotfricstop(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        ragdollconstrain.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_ragdollconstrain(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        ragdollbodyfric.onChange.connect([](const float oldvalue, const float newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_ragdollbodyfric(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        ragdollbodyfricscale.onChange.connect([](const float oldvalue, const float newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_ragdollbodyfricscale(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        ragdollwaterfric.onChange.connect([](const float oldvalue, const float newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_ragdollwaterfric(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        ragdollgroundfric.onChange.connect([](const float oldvalue, const float newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_ragdollgroundfric(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        ragdollairfric.onChange.connect([](const float oldvalue, const float newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_ragdollairfric(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        ragdollunstick.onChange.connect([](const float oldvalue, const float newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_ragdollunstick(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        ragdollexpireoffset.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_ragdollexpireoffset(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        ragdollwaterexpireoffset.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_ragdollwaterexpireoffset(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        ragdolleyesmooth.onChange.connect([](const float oldvalue, const float newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_ragdolleyesmooth(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        ragdolleyesmoothmillis.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_ragdolleyesmoothmillis(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        glversion.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_glversion(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        glslversion.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_glslversion(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        ati_skybox_bug.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_ati_skybox_bug(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        ati_minmax_bug.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_ati_minmax_bug(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        ati_cubemap_bug.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_ati_cubemap_bug(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        intel_vertexarray_bug.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_intel_vertexarray_bug(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        intel_mapbufferrange_bug.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_intel_mapbufferrange_bug(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        minimizetcusage.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_minimizetcusage(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        useubo.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_useubo(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        usetexcompress.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_usetexcompress(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        rtscissor.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_rtscissor(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        blurtile.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_blurtile(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        rtsharefb.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_rtsharefb(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        dbgexts.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_dbgexts(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        wireframe.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_wireframe(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        zoominvel.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_zoominvel(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        zoomoutvel.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_zoomoutvel(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        zoomfov.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_zoomfov(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        fov.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_fov(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        followfov.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_followfov(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        avatarzoomfov.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_avatarzoomfov(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        avatarfov.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_avatarfov(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        avatardepth.onChange.connect([](const float oldvalue, const float newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_avatardepth(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        forceaspect.onChange.connect([](const float oldvalue, const float newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_forceaspect(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        zoom.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_zoom(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        zoomsens.onChange.connect([](const float oldvalue, const float newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_zoomsens(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        zoomaccel.onChange.connect([](const float oldvalue, const float newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_zoomaccel(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        zoomautosens.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_zoomautosens(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        sensitivity.onChange.connect([](const float oldvalue, const float newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_sensitivity(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        sensitivityscale.onChange.connect([](const float oldvalue, const float newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_sensitivityscale(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        invmouse.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_invmouse(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        mouseaccel.onChange.connect([](const float oldvalue, const float newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_mouseaccel(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        thirdperson.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_thirdperson(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        thirdpersondistance.onChange.connect([](const float oldvalue, const float newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_thirdpersondistance(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        thirdpersonup.onChange.connect([](const float oldvalue, const float newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_thirdpersonup(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        thirdpersonside.onChange.connect([](const float oldvalue, const float newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_thirdpersonside(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        nearplane.onChange.connect([](const float oldvalue, const float newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_nearplane(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        reflectclip.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_reflectclip(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        reflectclipavatar.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_reflectclipavatar(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        polygonoffsetfactor.onChange.connect([](const float oldvalue, const float newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_polygonoffsetfactor(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        polygonoffsetunits.onChange.connect([](const float oldvalue, const float newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_polygonoffsetunits(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        depthoffset.onChange.connect([](const float oldvalue, const float newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_depthoffset(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        fog.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_fog(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        fogcolour.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_fogcolour(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        skyboxglare.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_skyboxglare(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        reflectmms.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_reflectmms(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        refractsky.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_refractsky(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        modelpreviewfov.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_modelpreviewfov(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        modelpreviewpitch.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_modelpreviewpitch(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        minimapheight.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_minimapheight(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        minimapcolour.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_minimapcolour(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        minimapclip.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_minimapclip(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        minimapsize.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_minimapsize(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        motionblur.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_motionblur(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        motionblurmillis.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_motionblurmillis(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        motionblurscale.onChange.connect([](const float oldvalue, const float newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_motionblurscale(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        usedamagecompass.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_usedamagecompass(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        damagecompassfade.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_damagecompassfade(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        damagecompasssize.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_damagecompasssize(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        damagecompassalpha.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_damagecompassalpha(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        damagecompassmin.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_damagecompassmin(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        damagecompassmax.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_damagecompassmax(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        damagescreen.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_damagescreen(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        damagescreenfactor.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_damagescreenfactor(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        damagescreenalpha.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_damagescreenalpha(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        damagescreenfade.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_damagescreenfade(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        damagescreenmin.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_damagescreenmin(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        damagescreenmax.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_damagescreenmax(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        hidestats.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_hidestats(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        hidehud.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_hidehud(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        crosshairsize.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_crosshairsize(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        cursorsize.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_cursorsize(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        crosshairfx.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_crosshairfx(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        crosshaircolors.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_crosshaircolors(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        crosshairdir.onChange.connect([](const char* oldvalue, const char* newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_crosshairdir(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        cursor.onChange.connect([](const char* oldvalue, const char* newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_cursor(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        wallclock.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_wallclock(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        wallclock24.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_wallclock24(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        wallclocksecs.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_wallclocksecs(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        showfps.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_showfps(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        showfpsrange.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_showfpsrange(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        showeditstats.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_showeditstats(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        statrate.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_statrate(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        conscale.onChange.connect([](const float oldvalue, const float newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_conscale(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        modeldir.onChange.connect([](const char* oldvalue, const char* newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_modeldir(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        oqdynent.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_oqdynent(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        animationinterpolationtime.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_animationinterpolationtime(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        showboundingbox.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_showboundingbox(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        maxmodelradiusdistance.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_maxmodelradiusdistance(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        animoverride.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_animoverride(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        testanims.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_testanims(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        testpitch.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_testpitch(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        particlesize.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_particlesize(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        emitmillis.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_emitmillis(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        showparticles.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_showparticles(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        cullparticles.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_cullparticles(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        replayparticles.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_replayparticles(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        seedmillis.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_seedmillis(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        dbgpcull.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_dbgpcull(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        dbgpseed.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_dbgpseed(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        outlinemeters.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_outlinemeters(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        maxparticles.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_maxparticles(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        fewparticles.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_fewparticles(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        particleglare.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_particleglare(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        dbgparts.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_dbgparts(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        maxparticledistance.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_maxparticledistance(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        maxtrail.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_maxtrail(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        particletext.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_particletext(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        maxparticletextdistance.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_maxparticletextdistance(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        skybox.onChange.connect([](const char* oldvalue, const char* newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_skybox(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        skyboxcolour.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_skyboxcolour(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        spinsky.onChange.connect([](const float oldvalue, const float newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_spinsky(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        yawsky.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_yawsky(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        cloudbox.onChange.connect([](const char* oldvalue, const char* newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_cloudbox(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        cloudboxcolour.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_cloudboxcolour(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        cloudboxalpha.onChange.connect([](const float oldvalue, const float newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_cloudboxalpha(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        spinclouds.onChange.connect([](const float oldvalue, const float newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_spinclouds(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        yawclouds.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_yawclouds(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        cloudclip.onChange.connect([](const float oldvalue, const float newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_cloudclip(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        cloudlayer.onChange.connect([](const char* oldvalue, const char* newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_cloudlayer(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        cloudoffsetx.onChange.connect([](const float oldvalue, const float newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_cloudoffsetx(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        cloudoffsety.onChange.connect([](const float oldvalue, const float newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_cloudoffsety(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        cloudscrollx.onChange.connect([](const float oldvalue, const float newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_cloudscrollx(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        cloudscrolly.onChange.connect([](const float oldvalue, const float newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_cloudscrolly(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        cloudscale.onChange.connect([](const float oldvalue, const float newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_cloudscale(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        spincloudlayer.onChange.connect([](const float oldvalue, const float newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_spincloudlayer(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        yawcloudlayer.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_yawcloudlayer(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        cloudheight.onChange.connect([](const float oldvalue, const float newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_cloudheight(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        cloudfade.onChange.connect([](const float oldvalue, const float newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_cloudfade(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        cloudalpha.onChange.connect([](const float oldvalue, const float newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_cloudalpha(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        cloudsubdiv.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_cloudsubdiv(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        cloudcolour.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_cloudcolour(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        fogdomeheight.onChange.connect([](const float oldvalue, const float newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_fogdomeheight(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        fogdomemin.onChange.connect([](const float oldvalue, const float newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_fogdomemin(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        fogdomemax.onChange.connect([](const float oldvalue, const float newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_fogdomemax(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        fogdomecap.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_fogdomecap(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        fogdomeclip.onChange.connect([](const float oldvalue, const float newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_fogdomeclip(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        fogdomecolour.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_fogdomecolour(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        sparklyfix.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_sparklyfix(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        showsky.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_showsky(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        clipsky.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_clipsky(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        clampsky.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_clampsky(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        fogdomeclouds.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_fogdomeclouds(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        useskytexture.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_useskytexture(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        oqfrags.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_oqfrags(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        oqwait.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_oqwait(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        oqmm.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_oqmm(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        outline.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_outline(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        outlinecolour.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_outlinecolour(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        dtoutline.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_dtoutline(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        blendbrushcolor.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_blendbrushcolor(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        oqdist.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_oqdist(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        zpass.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_zpass(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        glowpass.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_glowpass(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        envpass.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_envpass(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        batchgeom.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_batchgeom(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        causticdir.onChange.connect([](const char* oldvalue, const char* newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_causticdir(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        causticscale.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_causticscale(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        causticmillis.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_causticmillis(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        caustics.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_caustics(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        oqgeom.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_oqgeom(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        compresspng.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_compresspng(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        compresstga.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_compresstga(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        screenshotdir.onChange.connect([](const char* oldvalue, const char* newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_screenshotdir(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        screenshotformat.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_screenshotformat(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        searchlan.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_searchlan(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        servpingrate.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_servpingrate(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        servpingdecay.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_servpingdecay(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        maxservpings.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_maxservpings(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        autosortservers.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_autosortservers(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        autoupdateservers.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_autoupdateservers(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        reservevpparams.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_reservevpparams(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        maxvsuniforms.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_maxvsuniforms(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        maxfsuniforms.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_maxfsuniforms(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        maxvaryings.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_maxvaryings(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        dbgshader.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_dbgshader(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        dbgubo.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_dbgubo(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        shaderprecision.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_shaderprecision(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        defershaders.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_defershaders(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        shaderdetail.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_shaderdetail(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        shadowmap.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_shadowmap(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        shadowmapsize.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_shadowmapsize(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        shadowmapradius.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_shadowmapradius(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        shadowmapheight.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_shadowmapheight(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        shadowmapdist.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_shadowmapdist(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        fpshadowmap.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_fpshadowmap(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        shadowmapprecision.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_shadowmapprecision(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        shadowmapambient.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_shadowmapambient(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        shadowmapintensity.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_shadowmapintensity(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        blurshadowmap.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_blurshadowmap(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        blursmsigma.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_blursmsigma(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        shadowmapcasters.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_shadowmapcasters(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        shadowmapangle.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_shadowmapangle(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        shadowmapbias.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_shadowmapbias(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        shadowmappeelbias.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_shadowmappeelbias(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        smdepthpeel.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_smdepthpeel(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        smoothshadowmappeel.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_smoothshadowmappeel(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        debugsm.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_debugsm(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        gpuskel.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_gpuskel(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        maxskelanimdata.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_maxskelanimdata(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        testtags.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_testtags(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        autocompactvslots.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_autocompactvslots(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        dbggz.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_dbggz(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        hwtexsize.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_hwtexsize(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        hwcubetexsize.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_hwcubetexsize(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        hwmaxaniso.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_hwmaxaniso(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        maxtexsize.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_maxtexsize(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        reducefilter.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_reducefilter(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        texreduce.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_texreduce(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        trilinear.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_trilinear(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        bilinear.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_bilinear(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        aniso.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_aniso(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        texcompress.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_texcompress(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        texcompressquality.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_texcompressquality(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        usenp2.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_usenp2(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        usedds.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_usedds(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        scaledds.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_scaledds(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        waterreflect.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_waterreflect(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        waterrefract.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_waterrefract(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        waterenvmap.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_waterenvmap(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        waterfallrefract.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_waterfallrefract(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        watersubdiv.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_watersubdiv(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        waterlod.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_waterlod(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        vertwater.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_vertwater(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        reflectdist.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_reflectdist(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        watercolour.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_watercolour(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        waterfog.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_waterfog(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        waterspec.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_waterspec(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        waterfallcolour.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_waterfallcolour(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        water2colour.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_water2colour(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        water2fog.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_water2fog(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        water2spec.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_water2spec(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        water2fallcolour.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_water2fallcolour(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        water3colour.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_water3colour(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        water3fog.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_water3fog(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        water3spec.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_water3spec(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        water3fallcolour.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_water3fallcolour(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        water4colour.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_water4colour(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        water4fog.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_water4fog(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        water4spec.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_water4spec(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        water4fallcolour.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_water4fallcolour(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        lavacolour.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_lavacolour(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        lavafog.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_lavafog(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        lava2colour.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_lava2colour(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        lava2fog.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_lava2fog(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        lava3colour.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_lava3colour(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        lava3fog.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_lava3fog(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        lava4colour.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_lava4colour(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        lava4fog.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_lava4fog(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        oqwater.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_oqwater(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        waterfade.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_waterfade(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        reflectsize.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_reflectsize(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        maxreflect.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_maxreflect(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        maskreflect.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_maskreflect(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        reflectscissor.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_reflectscissor(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        reflectvfc.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_reflectvfc(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        refractclear.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_refractclear(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        savebak.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_savebak(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        dbgvars.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_dbgvars(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        mapversion.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_mapversion(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        worldscale.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_worldscale(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        worldsize.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_worldsize(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        maptitle.onChange.connect([](const char* oldvalue, const char* newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_maptitle(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        octaentsize.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_octaentsize(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        entselradius.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_entselradius(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        entediting.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_entediting(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        attachradius.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_attachradius(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        entselsnap.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_entselsnap(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        entmovingshadow.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_entmovingshadow(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        showentradius.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_showentradius(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        entitysurf.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_entitysurf(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        entautoviewdist.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_entautoviewdist(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        entdrop.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_entdrop(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );
        dbgzip.onChange.connect([](const int oldvalue, const int newvalue)
            {
                inexor::tree::TreeNodeChanged val;
                val.set_dbgzip(newvalue);
                main2net_interthread_queue.enqueue(std::move(val));
            }
        );

    }

    void syncall()
    {
        // TODO: Dont call by type but by reference if not a ptr: *or& -> {cpp_observer_type}
        guiautotab.sync();
        guiclicktab.sync();
        guifadein.sync();
        guipushdist.sync();
        guisens.sync();
        useguifollow.sync();
        usegui2d.sync();
        envmapmodels.sync();
        bumpmodels.sync();
        fullbrightmodels.sync();
        blendpaintmode.sync();
        paintblendmapdelay.sync();
        paintblendmapinterval.sync();
        showblobs.sync();
        blobintensity.sync();
        blobheight.sync();
        blobfadelow.sync();
        blobfadehigh.sync();
        blobmargin.sync();
        dbgblob.sync();
        blobstattris.sync();
        blobdyntris.sync();
        _numargs.sync();
        dbgalias.sync();
        dbgdds.sync();
        maxcon.sync();
        confading.sync();
        fullconsole.sync();
        consize.sync();
        miniconsize.sync();
        miniconwidth.sync();
        confade.sync();
        miniconfade.sync();
        fullconsize.sync();
        confilter.sync();
        fullconfilter.sync();
        miniconfilter.sync();
        maxhistory.sync();
        envmapsize.sync();
        envmapradius.sync();
        aaenvmap.sync();
        maxdecaltris.sync();
        decalfade.sync();
        dbgdec.sync();
        showdecals.sync();
        maxdecaldistance.sync();
        depthfxfpscale.sync();
        depthfxscale.sync();
        depthfxblend.sync();
        depthfxpartblend.sync();
        depthfxmargin.sync();
        depthfxbias.sync();
        fpdepthfx.sync();
        depthfxemuprecision.sync();
        depthfxsize.sync();
        depthfx.sync();
        depthfxparts.sync();
        blurdepthfx.sync();
        blurdepthfxsigma.sync();
        depthfxscissor.sync();
        debugdepthfx.sync();
        maxdynlights.sync();
        dynlightdist.sync();
        rate.sync();
        throttle_interval.sync();
        throttle_accel.sync();
        throttle_decel.sync();
        connectname.sync();
        connectport.sync();
        fsaa.sync();
        background.sync();
        logo.sync();
        userelativemouse.sync();
        menufps.sync();
        maxfps.sync();
        clockerror.sync();
        clockfix.sync();
        numcpus.sync();
        maxclients.sync();
        maxdupclients.sync();
        allowupdatemaster.sync();
        mastername.sync();
        masterport.sync();
        serveruprate.sync();
        serverip.sync();
        serverport.sync();
        glaresize.sync();
        glare.sync();
        blurglare.sync();
        blurglaresigma.sync();
        debugglare.sync();
        glarescale.sync();
        grass.sync();
        dbggrass.sync();
        grassdist.sync();
        grasstaper.sync();
        grassstep.sync();
        grassheight.sync();
        grassanimmillis.sync();
        grassanimscale.sync();
        grassscale.sync();
        grasscolour.sync();
        grassalpha.sync();
        flarelights.sync();
        flarecutoff.sync();
        flaresize.sync();
        lightprecision.sync();
        lighterror.sync();
        bumperror.sync();
        lightlod.sync();
        ambient.sync();
        skylight.sync();
        sunlight.sync();
        sunlightscale.sync();
        sunlightyaw.sync();
        sunlightpitch.sync();
        skytexturelight.sync();
        lmshadows_.sync();
        lmaa_.sync();
        lerptjoints_.sync();
        lmao_.sync();
        lightcompress.sync();
        ambientocclusion.sync();
        ambientocclusionradius.sync();
        debugao.sync();
        blurlms.sync();
        blurskylight.sync();
        edgetolerance.sync();
        adaptivesample.sync();
        lightcachesize.sync();
        lightthreads.sync();
        patchnormals.sync();
        fullbright.sync();
        fullbrightlevel.sync();
        roundlightmaptex.sync();
        batchlightmaps.sync();
        lnjittermillis.sync();
        lnjitterradius.sync();
        lnjitterscale.sync();
        lnscrollmillis.sync();
        lnscrollscale.sync();
        lnblendpower.sync();
        optmats.sync();
        showmat.sync();
        glasscolour.sync();
        glass2colour.sync();
        glass3colour.sync();
        glass4colour.sync();
        glassenv.sync();
        waterfallenv.sync();
        mapdir.sync();
        texturedir.sync();
        skyboxdir.sync();
        interfacedir.sync();
        icondir.sync();
        sounddir.sync();
        musicdir.sync();
        menudistance.sync();
        menuautoclose.sync();
        applydialog.sync();
        mainmenu.sync();
        dbgmovie.sync();
        movieaccelblit.sync();
        movieaccelyuv.sync();
        movieaccel.sync();
        moviesync.sync();
        movieminquality.sync();
        moview.sync();
        movieh.sync();
        moviefps.sync();
        moviesound.sync();
        ai::aidebug.sync();
        ai::aiforcegun.sync();
        ai::showwaypoints.sync();
        ai::showwaypointsradius.sync();
        ai::dropwaypoints.sync();
        entities::triggerstate.sync();
        game::minradarscale.sync();
        game::maxradarscale.sync();
        game::radarteammates.sync();
        game::minimapalpha.sync();
        game::radardir.sync();
        game::capturetether.sync();
        game::autorepammo.sync();
        game::basenumbers.sync();
        game::showbombs.sync();
        game::showbombradius.sync();
        game::showbombdelay.sync();
        game::showminimapobstacles.sync();
        game::deadpush.sync();
        game::autoauth.sync();
        game::smoothmove.sync();
        game::smoothdist.sync();
        game::slowmosp.sync();
        game::spawnwait.sync();
        game::hitsound.sync();
        game::teamcolorfrags.sync();
        game::showmodeinfo.sync();
        game::teamcolortext.sync();
        game::ammohud.sync();
        game::teamcrosshair.sync();
        game::hitcrosshair.sync();
        game::skill.sync();
        game::killsendsp.sync();
        game::ragdoll.sync();
        game::ragdollmillis.sync();
        game::ragdollfade.sync();
        game::forceplayermodels.sync();
        game::hidedead.sync();
        game::testquad.sync();
        game::testarmour.sync();
        game::hudgun.sync();
        game::hudgunsway.sync();
        game::teamhudguns.sync();
        game::chainsawhudgun.sync();
        game::testhudgun.sync();
        game::swaystep.sync();
        game::swayside.sync();
        game::swayup.sync();
        game::hudgunsdir.sync();
        game::scoreboard2d.sync();
        game::showservinfo.sync();
        game::showclientnum.sync();
        game::showpj.sync();
        game::showping.sync();
        game::showspectators.sync();
        game::showflags.sync();
        game::showfrags.sync();
        game::showaccuracy.sync();
        game::highlightscore.sync();
        game::showconnecting.sync();
        game::showscoreboard.sync();
        game::maxdebris.sync();
        game::maxbarreldebris.sync();
        game::blood.sync();
        game::muzzleflash.sync();
        game::muzzlelight.sync();
        game::bombcolliderad.sync();
        game::bombbarrier.sync();
        game::deathscore.sync();
        game::playermodel.sync();
        game::testteam.sync();
        game::teamskins.sync();
        inexor::rendering::screen::scr_w.sync();
        inexor::rendering::screen::scr_h.sync();
        inexor::rendering::screen::colorbits.sync();
        inexor::rendering::screen::depthbits.sync();
        inexor::rendering::screen::stencilbits.sync();
        inexor::rendering::screen::gamma.sync();
        inexor::rendering::screen::vsync.sync();
        inexor::rendering::screen::vsynctear.sync();
        inexor::rendering::screen::fullscreen.sync();
        inexor::sound::soundvol.sync();
        inexor::sound::musicvol.sync();
        inexor::sound::stereo.sync();
        inexor::sound::maxsoundradius.sync();
        inexor::sound::maxsoundsatonce.sync();
        inexor::sound::dbgsound.sync();
        inexor::sound::mumble.sync();
        inexor::sound::soundchans.sync();
        inexor::sound::soundfreq.sync();
        inexor::sound::soundbufferlen.sync();
        server::lockmaprotation.sync();
        server::maxdemos.sync();
        server::maxdemosize.sync();
        server::restrictdemos.sync();
        server::restrictpausegame.sync();
        server::restrictgamespeed.sync();
        server::restrictpersistteams.sync();
        server::serverdesc.sync();
        server::serverpass.sync();
        server::adminpass.sync();
        server::publicserver.sync();
        server::servermotd.sync();
        server::spectatemodifiedmap.sync();
        server::ctftkpenalty.sync();
        server::serverauth.sync();
        server::modifiedmapspectator.sync();
        server::extinfoip.sync();
        server::aiman::botlimit.sync();
        server::aiman::serverbotbalance.sync();
        lerpangle.sync();
        lerpsubdiv.sync();
        lerpsubdivsize.sync();
        dragging.sync();
        gridpower.sync();
        passthroughsel.sync();
        editing.sync();
        selectcorners.sync();
        hmapedit.sync();
        gridlookup.sync();
        passthroughcube.sync();
        undomegs.sync();
        nompedit.sync();
        prefabdir.sync();
        brushx.sync();
        brushy.sync();
        invalidcubeguard.sync();
        selectionsurf.sync();
        usevdelta.sync();
        allfaces.sync();
        texguiwidth.sync();
        texguiheight.sync();
        texguitime.sync();
        texgui2d.sync();
        debugvbo.sync();
        maxvbosize.sync();
        filltjoints.sync();
        vafacemax.sync();
        vafacemin.sync();
        vacubesize.sync();
        mipvis.sync();
        maxmerge.sync();
        minface.sync();
        dynentsize.sync();
        maxroll.sync();
        straferoll.sync();
        faderoll.sync();
        floatspeed.sync();
        physinterp.sync();
        maxpvsblocker.sync();
        pvsleafsize.sync();
        pvsthreads.sync();
        lockpvs.sync();
        usepvs.sync();
        usewaterpvs.sync();
        ragdolltimestepmin.sync();
        ragdolltimestepmax.sync();
        ragdollrotfric.sync();
        ragdollrotfricstop.sync();
        ragdollconstrain.sync();
        ragdollbodyfric.sync();
        ragdollbodyfricscale.sync();
        ragdollwaterfric.sync();
        ragdollgroundfric.sync();
        ragdollairfric.sync();
        ragdollunstick.sync();
        ragdollexpireoffset.sync();
        ragdollwaterexpireoffset.sync();
        ragdolleyesmooth.sync();
        ragdolleyesmoothmillis.sync();
        glversion.sync();
        glslversion.sync();
        ati_skybox_bug.sync();
        ati_minmax_bug.sync();
        ati_cubemap_bug.sync();
        intel_vertexarray_bug.sync();
        intel_mapbufferrange_bug.sync();
        minimizetcusage.sync();
        useubo.sync();
        usetexcompress.sync();
        rtscissor.sync();
        blurtile.sync();
        rtsharefb.sync();
        dbgexts.sync();
        wireframe.sync();
        zoominvel.sync();
        zoomoutvel.sync();
        zoomfov.sync();
        fov.sync();
        followfov.sync();
        avatarzoomfov.sync();
        avatarfov.sync();
        avatardepth.sync();
        forceaspect.sync();
        zoom.sync();
        zoomsens.sync();
        zoomaccel.sync();
        zoomautosens.sync();
        sensitivity.sync();
        sensitivityscale.sync();
        invmouse.sync();
        mouseaccel.sync();
        thirdperson.sync();
        thirdpersondistance.sync();
        thirdpersonup.sync();
        thirdpersonside.sync();
        nearplane.sync();
        reflectclip.sync();
        reflectclipavatar.sync();
        polygonoffsetfactor.sync();
        polygonoffsetunits.sync();
        depthoffset.sync();
        fog.sync();
        fogcolour.sync();
        skyboxglare.sync();
        reflectmms.sync();
        refractsky.sync();
        modelpreviewfov.sync();
        modelpreviewpitch.sync();
        minimapheight.sync();
        minimapcolour.sync();
        minimapclip.sync();
        minimapsize.sync();
        motionblur.sync();
        motionblurmillis.sync();
        motionblurscale.sync();
        usedamagecompass.sync();
        damagecompassfade.sync();
        damagecompasssize.sync();
        damagecompassalpha.sync();
        damagecompassmin.sync();
        damagecompassmax.sync();
        damagescreen.sync();
        damagescreenfactor.sync();
        damagescreenalpha.sync();
        damagescreenfade.sync();
        damagescreenmin.sync();
        damagescreenmax.sync();
        hidestats.sync();
        hidehud.sync();
        crosshairsize.sync();
        cursorsize.sync();
        crosshairfx.sync();
        crosshaircolors.sync();
        crosshairdir.sync();
        cursor.sync();
        wallclock.sync();
        wallclock24.sync();
        wallclocksecs.sync();
        showfps.sync();
        showfpsrange.sync();
        showeditstats.sync();
        statrate.sync();
        conscale.sync();
        modeldir.sync();
        oqdynent.sync();
        animationinterpolationtime.sync();
        showboundingbox.sync();
        maxmodelradiusdistance.sync();
        animoverride.sync();
        testanims.sync();
        testpitch.sync();
        particlesize.sync();
        emitmillis.sync();
        showparticles.sync();
        cullparticles.sync();
        replayparticles.sync();
        seedmillis.sync();
        dbgpcull.sync();
        dbgpseed.sync();
        outlinemeters.sync();
        maxparticles.sync();
        fewparticles.sync();
        particleglare.sync();
        dbgparts.sync();
        maxparticledistance.sync();
        maxtrail.sync();
        particletext.sync();
        maxparticletextdistance.sync();
        skybox.sync();
        skyboxcolour.sync();
        spinsky.sync();
        yawsky.sync();
        cloudbox.sync();
        cloudboxcolour.sync();
        cloudboxalpha.sync();
        spinclouds.sync();
        yawclouds.sync();
        cloudclip.sync();
        cloudlayer.sync();
        cloudoffsetx.sync();
        cloudoffsety.sync();
        cloudscrollx.sync();
        cloudscrolly.sync();
        cloudscale.sync();
        spincloudlayer.sync();
        yawcloudlayer.sync();
        cloudheight.sync();
        cloudfade.sync();
        cloudalpha.sync();
        cloudsubdiv.sync();
        cloudcolour.sync();
        fogdomeheight.sync();
        fogdomemin.sync();
        fogdomemax.sync();
        fogdomecap.sync();
        fogdomeclip.sync();
        fogdomecolour.sync();
        sparklyfix.sync();
        showsky.sync();
        clipsky.sync();
        clampsky.sync();
        fogdomeclouds.sync();
        useskytexture.sync();
        oqfrags.sync();
        oqwait.sync();
        oqmm.sync();
        outline.sync();
        outlinecolour.sync();
        dtoutline.sync();
        blendbrushcolor.sync();
        oqdist.sync();
        zpass.sync();
        glowpass.sync();
        envpass.sync();
        batchgeom.sync();
        causticdir.sync();
        causticscale.sync();
        causticmillis.sync();
        caustics.sync();
        oqgeom.sync();
        compresspng.sync();
        compresstga.sync();
        screenshotdir.sync();
        screenshotformat.sync();
        searchlan.sync();
        servpingrate.sync();
        servpingdecay.sync();
        maxservpings.sync();
        autosortservers.sync();
        autoupdateservers.sync();
        reservevpparams.sync();
        maxvsuniforms.sync();
        maxfsuniforms.sync();
        maxvaryings.sync();
        dbgshader.sync();
        dbgubo.sync();
        shaderprecision.sync();
        defershaders.sync();
        shaderdetail.sync();
        shadowmap.sync();
        shadowmapsize.sync();
        shadowmapradius.sync();
        shadowmapheight.sync();
        shadowmapdist.sync();
        fpshadowmap.sync();
        shadowmapprecision.sync();
        shadowmapambient.sync();
        shadowmapintensity.sync();
        blurshadowmap.sync();
        blursmsigma.sync();
        shadowmapcasters.sync();
        shadowmapangle.sync();
        shadowmapbias.sync();
        shadowmappeelbias.sync();
        smdepthpeel.sync();
        smoothshadowmappeel.sync();
        debugsm.sync();
        gpuskel.sync();
        maxskelanimdata.sync();
        testtags.sync();
        autocompactvslots.sync();
        dbggz.sync();
        hwtexsize.sync();
        hwcubetexsize.sync();
        hwmaxaniso.sync();
        maxtexsize.sync();
        reducefilter.sync();
        texreduce.sync();
        trilinear.sync();
        bilinear.sync();
        aniso.sync();
        texcompress.sync();
        texcompressquality.sync();
        usenp2.sync();
        usedds.sync();
        scaledds.sync();
        waterreflect.sync();
        waterrefract.sync();
        waterenvmap.sync();
        waterfallrefract.sync();
        watersubdiv.sync();
        waterlod.sync();
        vertwater.sync();
        reflectdist.sync();
        watercolour.sync();
        waterfog.sync();
        waterspec.sync();
        waterfallcolour.sync();
        water2colour.sync();
        water2fog.sync();
        water2spec.sync();
        water2fallcolour.sync();
        water3colour.sync();
        water3fog.sync();
        water3spec.sync();
        water3fallcolour.sync();
        water4colour.sync();
        water4fog.sync();
        water4spec.sync();
        water4fallcolour.sync();
        lavacolour.sync();
        lavafog.sync();
        lava2colour.sync();
        lava2fog.sync();
        lava3colour.sync();
        lava3fog.sync();
        lava4colour.sync();
        lava4fog.sync();
        oqwater.sync();
        waterfade.sync();
        reflectsize.sync();
        maxreflect.sync();
        maskreflect.sync();
        reflectscissor.sync();
        reflectvfc.sync();
        refractclear.sync();
        savebak.sync();
        dbgvars.sync();
        mapversion.sync();
        worldscale.sync();
        worldsize.sync();
        maptitle.sync();
        octaentsize.sync();
        entselradius.sync();
        entediting.sync();
        attachradius.sync();
        entselsnap.sync();
        entmovingshadow.sync();
        showentradius.sync();
        entitysurf.sync();
        entautoviewdist.sync();
        entdrop.sync();
        dbgzip.sync();

    }

    /// (proto)index -> pointer to the to-be-updated-variable.
    const std::unordered_map<int64, void *> cppvar_pointer_map
    {
        // { index, pointer_to_the_changed_var (see net2maintupel::ptr2var) }
        { 1, (void *) &guiautotab },
        { 2, (void *) &guiclicktab },
        { 3, (void *) &guifadein },
        { 4, (void *) &guipushdist },
        { 5, (void *) &guisens },
        { 6, (void *) &useguifollow },
        { 7, (void *) &usegui2d },
        { 8, (void *) &envmapmodels },
        { 9, (void *) &bumpmodels },
        { 10, (void *) &fullbrightmodels },
        { 11, (void *) &blendpaintmode },
        { 12, (void *) &paintblendmapdelay },
        { 13, (void *) &paintblendmapinterval },
        { 14, (void *) &showblobs },
        { 15, (void *) &blobintensity },
        { 16, (void *) &blobheight },
        { 17, (void *) &blobfadelow },
        { 18, (void *) &blobfadehigh },
        { 19, (void *) &blobmargin },
        { 20, (void *) &dbgblob },
        { 21, (void *) &blobstattris },
        { 22, (void *) &blobdyntris },
        { 23, (void *) &_numargs },
        { 24, (void *) &dbgalias },
        { 25, (void *) &dbgdds },
        { 26, (void *) &maxcon },
        { 27, (void *) &confading },
        { 28, (void *) &fullconsole },
        { 29, (void *) &consize },
        { 30, (void *) &miniconsize },
        { 31, (void *) &miniconwidth },
        { 32, (void *) &confade },
        { 33, (void *) &miniconfade },
        { 34, (void *) &fullconsize },
        { 35, (void *) &confilter },
        { 36, (void *) &fullconfilter },
        { 37, (void *) &miniconfilter },
        { 38, (void *) &maxhistory },
        { 39, (void *) &envmapsize },
        { 40, (void *) &envmapradius },
        { 41, (void *) &aaenvmap },
        { 42, (void *) &maxdecaltris },
        { 43, (void *) &decalfade },
        { 44, (void *) &dbgdec },
        { 45, (void *) &showdecals },
        { 46, (void *) &maxdecaldistance },
        { 47, (void *) &depthfxfpscale },
        { 48, (void *) &depthfxscale },
        { 49, (void *) &depthfxblend },
        { 50, (void *) &depthfxpartblend },
        { 51, (void *) &depthfxmargin },
        { 52, (void *) &depthfxbias },
        { 53, (void *) &fpdepthfx },
        { 54, (void *) &depthfxemuprecision },
        { 55, (void *) &depthfxsize },
        { 56, (void *) &depthfx },
        { 57, (void *) &depthfxparts },
        { 58, (void *) &blurdepthfx },
        { 59, (void *) &blurdepthfxsigma },
        { 60, (void *) &depthfxscissor },
        { 61, (void *) &debugdepthfx },
        { 62, (void *) &maxdynlights },
        { 63, (void *) &dynlightdist },
        { 64, (void *) &rate },
        { 65, (void *) &throttle_interval },
        { 66, (void *) &throttle_accel },
        { 67, (void *) &throttle_decel },
        { 68, (void *) &connectname },
        { 69, (void *) &connectport },
        { 70, (void *) &fsaa },
        { 71, (void *) &background },
        { 72, (void *) &logo },
        { 73, (void *) &userelativemouse },
        { 74, (void *) &menufps },
        { 75, (void *) &maxfps },
        { 76, (void *) &clockerror },
        { 77, (void *) &clockfix },
        { 78, (void *) &numcpus },
        { 79, (void *) &maxclients },
        { 80, (void *) &maxdupclients },
        { 81, (void *) &allowupdatemaster },
        { 82, (void *) &mastername },
        { 83, (void *) &masterport },
        { 84, (void *) &serveruprate },
        { 85, (void *) &serverip },
        { 86, (void *) &serverport },
        { 87, (void *) &glaresize },
        { 88, (void *) &glare },
        { 89, (void *) &blurglare },
        { 90, (void *) &blurglaresigma },
        { 91, (void *) &debugglare },
        { 92, (void *) &glarescale },
        { 93, (void *) &grass },
        { 94, (void *) &dbggrass },
        { 95, (void *) &grassdist },
        { 96, (void *) &grasstaper },
        { 97, (void *) &grassstep },
        { 98, (void *) &grassheight },
        { 99, (void *) &grassanimmillis },
        { 100, (void *) &grassanimscale },
        { 101, (void *) &grassscale },
        { 102, (void *) &grasscolour },
        { 103, (void *) &grassalpha },
        { 104, (void *) &flarelights },
        { 105, (void *) &flarecutoff },
        { 106, (void *) &flaresize },
        { 107, (void *) &lightprecision },
        { 108, (void *) &lighterror },
        { 109, (void *) &bumperror },
        { 110, (void *) &lightlod },
        { 111, (void *) &ambient },
        { 112, (void *) &skylight },
        { 113, (void *) &sunlight },
        { 114, (void *) &sunlightscale },
        { 115, (void *) &sunlightyaw },
        { 116, (void *) &sunlightpitch },
        { 117, (void *) &skytexturelight },
        { 118, (void *) &lmshadows_ },
        { 119, (void *) &lmaa_ },
        { 120, (void *) &lerptjoints_ },
        { 121, (void *) &lmao_ },
        { 122, (void *) &lightcompress },
        { 123, (void *) &ambientocclusion },
        { 124, (void *) &ambientocclusionradius },
        { 125, (void *) &debugao },
        { 126, (void *) &blurlms },
        { 127, (void *) &blurskylight },
        { 128, (void *) &edgetolerance },
        { 129, (void *) &adaptivesample },
        { 130, (void *) &lightcachesize },
        { 131, (void *) &lightthreads },
        { 132, (void *) &patchnormals },
        { 133, (void *) &fullbright },
        { 134, (void *) &fullbrightlevel },
        { 135, (void *) &roundlightmaptex },
        { 136, (void *) &batchlightmaps },
        { 137, (void *) &lnjittermillis },
        { 138, (void *) &lnjitterradius },
        { 139, (void *) &lnjitterscale },
        { 140, (void *) &lnscrollmillis },
        { 141, (void *) &lnscrollscale },
        { 142, (void *) &lnblendpower },
        { 143, (void *) &optmats },
        { 144, (void *) &showmat },
        { 145, (void *) &glasscolour },
        { 146, (void *) &glass2colour },
        { 147, (void *) &glass3colour },
        { 148, (void *) &glass4colour },
        { 149, (void *) &glassenv },
        { 150, (void *) &waterfallenv },
        { 151, (void *) &mapdir },
        { 152, (void *) &texturedir },
        { 153, (void *) &skyboxdir },
        { 154, (void *) &interfacedir },
        { 155, (void *) &icondir },
        { 156, (void *) &sounddir },
        { 157, (void *) &musicdir },
        { 158, (void *) &menudistance },
        { 159, (void *) &menuautoclose },
        { 160, (void *) &applydialog },
        { 161, (void *) &mainmenu },
        { 162, (void *) &dbgmovie },
        { 163, (void *) &movieaccelblit },
        { 164, (void *) &movieaccelyuv },
        { 165, (void *) &movieaccel },
        { 166, (void *) &moviesync },
        { 167, (void *) &movieminquality },
        { 168, (void *) &moview },
        { 169, (void *) &movieh },
        { 170, (void *) &moviefps },
        { 171, (void *) &moviesound },
        { 172, (void *) &ai::aidebug },
        { 173, (void *) &ai::aiforcegun },
        { 174, (void *) &ai::showwaypoints },
        { 175, (void *) &ai::showwaypointsradius },
        { 176, (void *) &ai::dropwaypoints },
        { 177, (void *) &entities::triggerstate },
        { 178, (void *) &game::minradarscale },
        { 179, (void *) &game::maxradarscale },
        { 180, (void *) &game::radarteammates },
        { 181, (void *) &game::minimapalpha },
        { 182, (void *) &game::radardir },
        { 183, (void *) &game::capturetether },
        { 184, (void *) &game::autorepammo },
        { 185, (void *) &game::basenumbers },
        { 186, (void *) &game::showbombs },
        { 187, (void *) &game::showbombradius },
        { 188, (void *) &game::showbombdelay },
        { 189, (void *) &game::showminimapobstacles },
        { 190, (void *) &game::deadpush },
        { 191, (void *) &game::autoauth },
        { 192, (void *) &game::smoothmove },
        { 193, (void *) &game::smoothdist },
        { 194, (void *) &game::slowmosp },
        { 195, (void *) &game::spawnwait },
        { 196, (void *) &game::hitsound },
        { 197, (void *) &game::teamcolorfrags },
        { 198, (void *) &game::showmodeinfo },
        { 199, (void *) &game::teamcolortext },
        { 200, (void *) &game::ammohud },
        { 201, (void *) &game::teamcrosshair },
        { 202, (void *) &game::hitcrosshair },
        { 203, (void *) &game::skill },
        { 204, (void *) &game::killsendsp },
        { 205, (void *) &game::ragdoll },
        { 206, (void *) &game::ragdollmillis },
        { 207, (void *) &game::ragdollfade },
        { 208, (void *) &game::forceplayermodels },
        { 209, (void *) &game::hidedead },
        { 210, (void *) &game::testquad },
        { 211, (void *) &game::testarmour },
        { 212, (void *) &game::hudgun },
        { 213, (void *) &game::hudgunsway },
        { 214, (void *) &game::teamhudguns },
        { 215, (void *) &game::chainsawhudgun },
        { 216, (void *) &game::testhudgun },
        { 217, (void *) &game::swaystep },
        { 218, (void *) &game::swayside },
        { 219, (void *) &game::swayup },
        { 220, (void *) &game::hudgunsdir },
        { 221, (void *) &game::scoreboard2d },
        { 222, (void *) &game::showservinfo },
        { 223, (void *) &game::showclientnum },
        { 224, (void *) &game::showpj },
        { 225, (void *) &game::showping },
        { 226, (void *) &game::showspectators },
        { 227, (void *) &game::showflags },
        { 228, (void *) &game::showfrags },
        { 229, (void *) &game::showaccuracy },
        { 230, (void *) &game::highlightscore },
        { 231, (void *) &game::showconnecting },
        { 232, (void *) &game::showscoreboard },
        { 233, (void *) &game::maxdebris },
        { 234, (void *) &game::maxbarreldebris },
        { 235, (void *) &game::blood },
        { 236, (void *) &game::muzzleflash },
        { 237, (void *) &game::muzzlelight },
        { 238, (void *) &game::bombcolliderad },
        { 239, (void *) &game::bombbarrier },
        { 240, (void *) &game::deathscore },
        { 241, (void *) &game::playermodel },
        { 242, (void *) &game::testteam },
        { 243, (void *) &game::teamskins },
        { 244, (void *) &inexor::rendering::screen::scr_w },
        { 245, (void *) &inexor::rendering::screen::scr_h },
        { 246, (void *) &inexor::rendering::screen::colorbits },
        { 247, (void *) &inexor::rendering::screen::depthbits },
        { 248, (void *) &inexor::rendering::screen::stencilbits },
        { 249, (void *) &inexor::rendering::screen::gamma },
        { 250, (void *) &inexor::rendering::screen::vsync },
        { 251, (void *) &inexor::rendering::screen::vsynctear },
        { 252, (void *) &inexor::rendering::screen::fullscreen },
        { 253, (void *) &inexor::sound::soundvol },
        { 254, (void *) &inexor::sound::musicvol },
        { 255, (void *) &inexor::sound::stereo },
        { 256, (void *) &inexor::sound::maxsoundradius },
        { 257, (void *) &inexor::sound::maxsoundsatonce },
        { 258, (void *) &inexor::sound::dbgsound },
        { 259, (void *) &inexor::sound::mumble },
        { 260, (void *) &inexor::sound::soundchans },
        { 261, (void *) &inexor::sound::soundfreq },
        { 262, (void *) &inexor::sound::soundbufferlen },
        { 263, (void *) &server::lockmaprotation },
        { 264, (void *) &server::maxdemos },
        { 265, (void *) &server::maxdemosize },
        { 266, (void *) &server::restrictdemos },
        { 267, (void *) &server::restrictpausegame },
        { 268, (void *) &server::restrictgamespeed },
        { 269, (void *) &server::restrictpersistteams },
        { 270, (void *) &server::serverdesc },
        { 271, (void *) &server::serverpass },
        { 272, (void *) &server::adminpass },
        { 273, (void *) &server::publicserver },
        { 274, (void *) &server::servermotd },
        { 275, (void *) &server::spectatemodifiedmap },
        { 276, (void *) &server::ctftkpenalty },
        { 277, (void *) &server::serverauth },
        { 278, (void *) &server::modifiedmapspectator },
        { 279, (void *) &server::extinfoip },
        { 280, (void *) &server::aiman::botlimit },
        { 281, (void *) &server::aiman::serverbotbalance },
        { 282, (void *) &lerpangle },
        { 283, (void *) &lerpsubdiv },
        { 284, (void *) &lerpsubdivsize },
        { 285, (void *) &dragging },
        { 286, (void *) &gridpower },
        { 287, (void *) &passthroughsel },
        { 288, (void *) &editing },
        { 289, (void *) &selectcorners },
        { 290, (void *) &hmapedit },
        { 291, (void *) &gridlookup },
        { 292, (void *) &passthroughcube },
        { 293, (void *) &undomegs },
        { 294, (void *) &nompedit },
        { 295, (void *) &prefabdir },
        { 296, (void *) &brushx },
        { 297, (void *) &brushy },
        { 298, (void *) &invalidcubeguard },
        { 299, (void *) &selectionsurf },
        { 300, (void *) &usevdelta },
        { 301, (void *) &allfaces },
        { 302, (void *) &texguiwidth },
        { 303, (void *) &texguiheight },
        { 304, (void *) &texguitime },
        { 305, (void *) &texgui2d },
        { 306, (void *) &debugvbo },
        { 307, (void *) &maxvbosize },
        { 308, (void *) &filltjoints },
        { 309, (void *) &vafacemax },
        { 310, (void *) &vafacemin },
        { 311, (void *) &vacubesize },
        { 312, (void *) &mipvis },
        { 313, (void *) &maxmerge },
        { 314, (void *) &minface },
        { 315, (void *) &dynentsize },
        { 316, (void *) &maxroll },
        { 317, (void *) &straferoll },
        { 318, (void *) &faderoll },
        { 319, (void *) &floatspeed },
        { 320, (void *) &physinterp },
        { 321, (void *) &maxpvsblocker },
        { 322, (void *) &pvsleafsize },
        { 323, (void *) &pvsthreads },
        { 324, (void *) &lockpvs },
        { 325, (void *) &usepvs },
        { 326, (void *) &usewaterpvs },
        { 327, (void *) &ragdolltimestepmin },
        { 328, (void *) &ragdolltimestepmax },
        { 329, (void *) &ragdollrotfric },
        { 330, (void *) &ragdollrotfricstop },
        { 331, (void *) &ragdollconstrain },
        { 332, (void *) &ragdollbodyfric },
        { 333, (void *) &ragdollbodyfricscale },
        { 334, (void *) &ragdollwaterfric },
        { 335, (void *) &ragdollgroundfric },
        { 336, (void *) &ragdollairfric },
        { 337, (void *) &ragdollunstick },
        { 338, (void *) &ragdollexpireoffset },
        { 339, (void *) &ragdollwaterexpireoffset },
        { 340, (void *) &ragdolleyesmooth },
        { 341, (void *) &ragdolleyesmoothmillis },
        { 342, (void *) &glversion },
        { 343, (void *) &glslversion },
        { 344, (void *) &ati_skybox_bug },
        { 345, (void *) &ati_minmax_bug },
        { 346, (void *) &ati_cubemap_bug },
        { 347, (void *) &intel_vertexarray_bug },
        { 348, (void *) &intel_mapbufferrange_bug },
        { 349, (void *) &minimizetcusage },
        { 350, (void *) &useubo },
        { 351, (void *) &usetexcompress },
        { 352, (void *) &rtscissor },
        { 353, (void *) &blurtile },
        { 354, (void *) &rtsharefb },
        { 355, (void *) &dbgexts },
        { 356, (void *) &wireframe },
        { 357, (void *) &zoominvel },
        { 358, (void *) &zoomoutvel },
        { 359, (void *) &zoomfov },
        { 360, (void *) &fov },
        { 361, (void *) &followfov },
        { 362, (void *) &avatarzoomfov },
        { 363, (void *) &avatarfov },
        { 364, (void *) &avatardepth },
        { 365, (void *) &forceaspect },
        { 366, (void *) &zoom },
        { 367, (void *) &zoomsens },
        { 368, (void *) &zoomaccel },
        { 369, (void *) &zoomautosens },
        { 370, (void *) &sensitivity },
        { 371, (void *) &sensitivityscale },
        { 372, (void *) &invmouse },
        { 373, (void *) &mouseaccel },
        { 374, (void *) &thirdperson },
        { 375, (void *) &thirdpersondistance },
        { 376, (void *) &thirdpersonup },
        { 377, (void *) &thirdpersonside },
        { 378, (void *) &nearplane },
        { 379, (void *) &reflectclip },
        { 380, (void *) &reflectclipavatar },
        { 381, (void *) &polygonoffsetfactor },
        { 382, (void *) &polygonoffsetunits },
        { 383, (void *) &depthoffset },
        { 384, (void *) &fog },
        { 385, (void *) &fogcolour },
        { 386, (void *) &skyboxglare },
        { 387, (void *) &reflectmms },
        { 388, (void *) &refractsky },
        { 389, (void *) &modelpreviewfov },
        { 390, (void *) &modelpreviewpitch },
        { 391, (void *) &minimapheight },
        { 392, (void *) &minimapcolour },
        { 393, (void *) &minimapclip },
        { 394, (void *) &minimapsize },
        { 395, (void *) &motionblur },
        { 396, (void *) &motionblurmillis },
        { 397, (void *) &motionblurscale },
        { 398, (void *) &usedamagecompass },
        { 399, (void *) &damagecompassfade },
        { 400, (void *) &damagecompasssize },
        { 401, (void *) &damagecompassalpha },
        { 402, (void *) &damagecompassmin },
        { 403, (void *) &damagecompassmax },
        { 404, (void *) &damagescreen },
        { 405, (void *) &damagescreenfactor },
        { 406, (void *) &damagescreenalpha },
        { 407, (void *) &damagescreenfade },
        { 408, (void *) &damagescreenmin },
        { 409, (void *) &damagescreenmax },
        { 410, (void *) &hidestats },
        { 411, (void *) &hidehud },
        { 412, (void *) &crosshairsize },
        { 413, (void *) &cursorsize },
        { 414, (void *) &crosshairfx },
        { 415, (void *) &crosshaircolors },
        { 416, (void *) &crosshairdir },
        { 417, (void *) &cursor },
        { 418, (void *) &wallclock },
        { 419, (void *) &wallclock24 },
        { 420, (void *) &wallclocksecs },
        { 421, (void *) &showfps },
        { 422, (void *) &showfpsrange },
        { 423, (void *) &showeditstats },
        { 424, (void *) &statrate },
        { 425, (void *) &conscale },
        { 426, (void *) &modeldir },
        { 427, (void *) &oqdynent },
        { 428, (void *) &animationinterpolationtime },
        { 429, (void *) &showboundingbox },
        { 430, (void *) &maxmodelradiusdistance },
        { 431, (void *) &animoverride },
        { 432, (void *) &testanims },
        { 433, (void *) &testpitch },
        { 434, (void *) &particlesize },
        { 435, (void *) &emitmillis },
        { 436, (void *) &showparticles },
        { 437, (void *) &cullparticles },
        { 438, (void *) &replayparticles },
        { 439, (void *) &seedmillis },
        { 440, (void *) &dbgpcull },
        { 441, (void *) &dbgpseed },
        { 442, (void *) &outlinemeters },
        { 443, (void *) &maxparticles },
        { 444, (void *) &fewparticles },
        { 445, (void *) &particleglare },
        { 446, (void *) &dbgparts },
        { 447, (void *) &maxparticledistance },
        { 448, (void *) &maxtrail },
        { 449, (void *) &particletext },
        { 450, (void *) &maxparticletextdistance },
        { 451, (void *) &skybox },
        { 452, (void *) &skyboxcolour },
        { 453, (void *) &spinsky },
        { 454, (void *) &yawsky },
        { 455, (void *) &cloudbox },
        { 456, (void *) &cloudboxcolour },
        { 457, (void *) &cloudboxalpha },
        { 458, (void *) &spinclouds },
        { 459, (void *) &yawclouds },
        { 460, (void *) &cloudclip },
        { 461, (void *) &cloudlayer },
        { 462, (void *) &cloudoffsetx },
        { 463, (void *) &cloudoffsety },
        { 464, (void *) &cloudscrollx },
        { 465, (void *) &cloudscrolly },
        { 466, (void *) &cloudscale },
        { 467, (void *) &spincloudlayer },
        { 468, (void *) &yawcloudlayer },
        { 469, (void *) &cloudheight },
        { 470, (void *) &cloudfade },
        { 471, (void *) &cloudalpha },
        { 472, (void *) &cloudsubdiv },
        { 473, (void *) &cloudcolour },
        { 474, (void *) &fogdomeheight },
        { 475, (void *) &fogdomemin },
        { 476, (void *) &fogdomemax },
        { 477, (void *) &fogdomecap },
        { 478, (void *) &fogdomeclip },
        { 479, (void *) &fogdomecolour },
        { 480, (void *) &sparklyfix },
        { 481, (void *) &showsky },
        { 482, (void *) &clipsky },
        { 483, (void *) &clampsky },
        { 484, (void *) &fogdomeclouds },
        { 485, (void *) &useskytexture },
        { 486, (void *) &oqfrags },
        { 487, (void *) &oqwait },
        { 488, (void *) &oqmm },
        { 489, (void *) &outline },
        { 490, (void *) &outlinecolour },
        { 491, (void *) &dtoutline },
        { 492, (void *) &blendbrushcolor },
        { 493, (void *) &oqdist },
        { 494, (void *) &zpass },
        { 495, (void *) &glowpass },
        { 496, (void *) &envpass },
        { 497, (void *) &batchgeom },
        { 498, (void *) &causticdir },
        { 499, (void *) &causticscale },
        { 500, (void *) &causticmillis },
        { 501, (void *) &caustics },
        { 502, (void *) &oqgeom },
        { 503, (void *) &compresspng },
        { 504, (void *) &compresstga },
        { 505, (void *) &screenshotdir },
        { 506, (void *) &screenshotformat },
        { 507, (void *) &searchlan },
        { 508, (void *) &servpingrate },
        { 509, (void *) &servpingdecay },
        { 510, (void *) &maxservpings },
        { 511, (void *) &autosortservers },
        { 512, (void *) &autoupdateservers },
        { 513, (void *) &reservevpparams },
        { 514, (void *) &maxvsuniforms },
        { 515, (void *) &maxfsuniforms },
        { 516, (void *) &maxvaryings },
        { 517, (void *) &dbgshader },
        { 518, (void *) &dbgubo },
        { 519, (void *) &shaderprecision },
        { 520, (void *) &defershaders },
        { 521, (void *) &shaderdetail },
        { 522, (void *) &shadowmap },
        { 523, (void *) &shadowmapsize },
        { 524, (void *) &shadowmapradius },
        { 525, (void *) &shadowmapheight },
        { 526, (void *) &shadowmapdist },
        { 527, (void *) &fpshadowmap },
        { 528, (void *) &shadowmapprecision },
        { 529, (void *) &shadowmapambient },
        { 530, (void *) &shadowmapintensity },
        { 531, (void *) &blurshadowmap },
        { 532, (void *) &blursmsigma },
        { 533, (void *) &shadowmapcasters },
        { 534, (void *) &shadowmapangle },
        { 535, (void *) &shadowmapbias },
        { 536, (void *) &shadowmappeelbias },
        { 537, (void *) &smdepthpeel },
        { 538, (void *) &smoothshadowmappeel },
        { 539, (void *) &debugsm },
        { 540, (void *) &gpuskel },
        { 541, (void *) &maxskelanimdata },
        { 542, (void *) &testtags },
        { 543, (void *) &autocompactvslots },
        { 544, (void *) &dbggz },
        { 545, (void *) &hwtexsize },
        { 546, (void *) &hwcubetexsize },
        { 547, (void *) &hwmaxaniso },
        { 548, (void *) &maxtexsize },
        { 549, (void *) &reducefilter },
        { 550, (void *) &texreduce },
        { 551, (void *) &trilinear },
        { 552, (void *) &bilinear },
        { 553, (void *) &aniso },
        { 554, (void *) &texcompress },
        { 555, (void *) &texcompressquality },
        { 556, (void *) &usenp2 },
        { 557, (void *) &usedds },
        { 558, (void *) &scaledds },
        { 559, (void *) &waterreflect },
        { 560, (void *) &waterrefract },
        { 561, (void *) &waterenvmap },
        { 562, (void *) &waterfallrefract },
        { 563, (void *) &watersubdiv },
        { 564, (void *) &waterlod },
        { 565, (void *) &vertwater },
        { 566, (void *) &reflectdist },
        { 567, (void *) &watercolour },
        { 568, (void *) &waterfog },
        { 569, (void *) &waterspec },
        { 570, (void *) &waterfallcolour },
        { 571, (void *) &water2colour },
        { 572, (void *) &water2fog },
        { 573, (void *) &water2spec },
        { 574, (void *) &water2fallcolour },
        { 575, (void *) &water3colour },
        { 576, (void *) &water3fog },
        { 577, (void *) &water3spec },
        { 578, (void *) &water3fallcolour },
        { 579, (void *) &water4colour },
        { 580, (void *) &water4fog },
        { 581, (void *) &water4spec },
        { 582, (void *) &water4fallcolour },
        { 583, (void *) &lavacolour },
        { 584, (void *) &lavafog },
        { 585, (void *) &lava2colour },
        { 586, (void *) &lava2fog },
        { 587, (void *) &lava3colour },
        { 588, (void *) &lava3fog },
        { 589, (void *) &lava4colour },
        { 590, (void *) &lava4fog },
        { 591, (void *) &oqwater },
        { 592, (void *) &waterfade },
        { 593, (void *) &reflectsize },
        { 594, (void *) &maxreflect },
        { 595, (void *) &maskreflect },
        { 596, (void *) &reflectscissor },
        { 597, (void *) &reflectvfc },
        { 598, (void *) &refractclear },
        { 599, (void *) &savebak },
        { 600, (void *) &dbgvars },
        { 601, (void *) &mapversion },
        { 602, (void *) &worldscale },
        { 603, (void *) &worldsize },
        { 604, (void *) &maptitle },
        { 605, (void *) &octaentsize },
        { 606, (void *) &entselradius },
        { 607, (void *) &entediting },
        { 608, (void *) &attachradius },
        { 609, (void *) &entselsnap },
        { 610, (void *) &entmovingshadow },
        { 611, (void *) &showentradius },
        { 612, (void *) &entitysurf },
        { 613, (void *) &entautoviewdist },
        { 614, (void *) &entdrop },
        { 615, (void *) &dbgzip },
    
    };

    /// (proto)index -> Data type (cpp_type_t)
    const std::unordered_map<int64, int> index_to_type_map
    {
        // { index, enum_type(string=0,float=1,int=2) }
        { 1, 2 },  // guiautotab, int
        { 2, 2 },  // guiclicktab, int
        { 3, 2 },  // guifadein, int
        { 4, 2 },  // guipushdist, int
        { 5, 1 },  // guisens, float
        { 6, 2 },  // useguifollow, int
        { 7, 2 },  // usegui2d, int
        { 8, 2 },  // envmapmodels, int
        { 9, 2 },  // bumpmodels, int
        { 10, 2 },  // fullbrightmodels, int
        { 11, 2 },  // blendpaintmode, int
        { 12, 2 },  // paintblendmapdelay, int
        { 13, 2 },  // paintblendmapinterval, int
        { 14, 2 },  // showblobs, int
        { 15, 2 },  // blobintensity, int
        { 16, 2 },  // blobheight, int
        { 17, 2 },  // blobfadelow, int
        { 18, 2 },  // blobfadehigh, int
        { 19, 2 },  // blobmargin, int
        { 20, 2 },  // dbgblob, int
        { 21, 2 },  // blobstattris, int
        { 22, 2 },  // blobdyntris, int
        { 23, 2 },  // _numargs, int
        { 24, 2 },  // dbgalias, int
        { 25, 2 },  // dbgdds, int
        { 26, 2 },  // maxcon, int
        { 27, 2 },  // confading, int
        { 28, 2 },  // fullconsole, int
        { 29, 2 },  // consize, int
        { 30, 2 },  // miniconsize, int
        { 31, 2 },  // miniconwidth, int
        { 32, 2 },  // confade, int
        { 33, 2 },  // miniconfade, int
        { 34, 2 },  // fullconsize, int
        { 35, 2 },  // confilter, int
        { 36, 2 },  // fullconfilter, int
        { 37, 2 },  // miniconfilter, int
        { 38, 2 },  // maxhistory, int
        { 39, 2 },  // envmapsize, int
        { 40, 2 },  // envmapradius, int
        { 41, 2 },  // aaenvmap, int
        { 42, 2 },  // maxdecaltris, int
        { 43, 2 },  // decalfade, int
        { 44, 2 },  // dbgdec, int
        { 45, 2 },  // showdecals, int
        { 46, 2 },  // maxdecaldistance, int
        { 47, 2 },  // depthfxfpscale, int
        { 48, 2 },  // depthfxscale, int
        { 49, 2 },  // depthfxblend, int
        { 50, 2 },  // depthfxpartblend, int
        { 51, 2 },  // depthfxmargin, int
        { 52, 2 },  // depthfxbias, int
        { 53, 2 },  // fpdepthfx, int
        { 54, 2 },  // depthfxemuprecision, int
        { 55, 2 },  // depthfxsize, int
        { 56, 2 },  // depthfx, int
        { 57, 2 },  // depthfxparts, int
        { 58, 2 },  // blurdepthfx, int
        { 59, 2 },  // blurdepthfxsigma, int
        { 60, 2 },  // depthfxscissor, int
        { 61, 2 },  // debugdepthfx, int
        { 62, 2 },  // maxdynlights, int
        { 63, 2 },  // dynlightdist, int
        { 64, 2 },  // rate, int
        { 65, 2 },  // throttle_interval, int
        { 66, 2 },  // throttle_accel, int
        { 67, 2 },  // throttle_decel, int
        { 68, 0 },  // connectname, char*
        { 69, 2 },  // connectport, int
        { 70, 2 },  // fsaa, int
        { 71, 0 },  // background, char*
        { 72, 0 },  // logo, char*
        { 73, 2 },  // userelativemouse, int
        { 74, 2 },  // menufps, int
        { 75, 2 },  // maxfps, int
        { 76, 2 },  // clockerror, int
        { 77, 2 },  // clockfix, int
        { 78, 2 },  // numcpus, int
        { 79, 2 },  // maxclients, int
        { 80, 2 },  // maxdupclients, int
        { 81, 2 },  // allowupdatemaster, int
        { 82, 0 },  // mastername, char*
        { 83, 2 },  // masterport, int
        { 84, 2 },  // serveruprate, int
        { 85, 0 },  // serverip, char*
        { 86, 2 },  // serverport, int
        { 87, 2 },  // glaresize, int
        { 88, 2 },  // glare, int
        { 89, 2 },  // blurglare, int
        { 90, 2 },  // blurglaresigma, int
        { 91, 2 },  // debugglare, int
        { 92, 1 },  // glarescale, float
        { 93, 2 },  // grass, int
        { 94, 2 },  // dbggrass, int
        { 95, 2 },  // grassdist, int
        { 96, 1 },  // grasstaper, float
        { 97, 1 },  // grassstep, float
        { 98, 2 },  // grassheight, int
        { 99, 2 },  // grassanimmillis, int
        { 100, 1 },  // grassanimscale, float
        { 101, 2 },  // grassscale, int
        { 102, 2 },  // grasscolour, int
        { 103, 1 },  // grassalpha, float
        { 104, 2 },  // flarelights, int
        { 105, 2 },  // flarecutoff, int
        { 106, 2 },  // flaresize, int
        { 107, 2 },  // lightprecision, int
        { 108, 2 },  // lighterror, int
        { 109, 2 },  // bumperror, int
        { 110, 2 },  // lightlod, int
        { 111, 2 },  // ambient, int
        { 112, 2 },  // skylight, int
        { 113, 2 },  // sunlight, int
        { 114, 1 },  // sunlightscale, float
        { 115, 2 },  // sunlightyaw, int
        { 116, 2 },  // sunlightpitch, int
        { 117, 2 },  // skytexturelight, int
        { 118, 2 },  // lmshadows_, int
        { 119, 2 },  // lmaa_, int
        { 120, 2 },  // lerptjoints_, int
        { 121, 2 },  // lmao_, int
        { 122, 2 },  // lightcompress, int
        { 123, 2 },  // ambientocclusion, int
        { 124, 1 },  // ambientocclusionradius, float
        { 125, 2 },  // debugao, int
        { 126, 2 },  // blurlms, int
        { 127, 2 },  // blurskylight, int
        { 128, 2 },  // edgetolerance, int
        { 129, 2 },  // adaptivesample, int
        { 130, 2 },  // lightcachesize, int
        { 131, 2 },  // lightthreads, int
        { 132, 2 },  // patchnormals, int
        { 133, 2 },  // fullbright, int
        { 134, 2 },  // fullbrightlevel, int
        { 135, 2 },  // roundlightmaptex, int
        { 136, 2 },  // batchlightmaps, int
        { 137, 2 },  // lnjittermillis, int
        { 138, 2 },  // lnjitterradius, int
        { 139, 1 },  // lnjitterscale, float
        { 140, 2 },  // lnscrollmillis, int
        { 141, 1 },  // lnscrollscale, float
        { 142, 1 },  // lnblendpower, float
        { 143, 2 },  // optmats, int
        { 144, 2 },  // showmat, int
        { 145, 2 },  // glasscolour, int
        { 146, 2 },  // glass2colour, int
        { 147, 2 },  // glass3colour, int
        { 148, 2 },  // glass4colour, int
        { 149, 2 },  // glassenv, int
        { 150, 2 },  // waterfallenv, int
        { 151, 0 },  // mapdir, char*
        { 152, 0 },  // texturedir, char*
        { 153, 0 },  // skyboxdir, char*
        { 154, 0 },  // interfacedir, char*
        { 155, 0 },  // icondir, char*
        { 156, 0 },  // sounddir, char*
        { 157, 0 },  // musicdir, char*
        { 158, 2 },  // menudistance, int
        { 159, 2 },  // menuautoclose, int
        { 160, 2 },  // applydialog, int
        { 161, 2 },  // mainmenu, int
        { 162, 2 },  // dbgmovie, int
        { 163, 2 },  // movieaccelblit, int
        { 164, 2 },  // movieaccelyuv, int
        { 165, 2 },  // movieaccel, int
        { 166, 2 },  // moviesync, int
        { 167, 1 },  // movieminquality, float
        { 168, 2 },  // moview, int
        { 169, 2 },  // movieh, int
        { 170, 2 },  // moviefps, int
        { 171, 2 },  // moviesound, int
        { 172, 2 },  // ai/aidebug, int
        { 173, 2 },  // ai/aiforcegun, int
        { 174, 2 },  // ai/showwaypoints, int
        { 175, 2 },  // ai/showwaypointsradius, int
        { 176, 2 },  // ai/dropwaypoints, int
        { 177, 2 },  // entities/triggerstate, int
        { 178, 2 },  // game/minradarscale, int
        { 179, 2 },  // game/maxradarscale, int
        { 180, 2 },  // game/radarteammates, int
        { 181, 1 },  // game/minimapalpha, float
        { 182, 0 },  // game/radardir, char*
        { 183, 2 },  // game/capturetether, int
        { 184, 2 },  // game/autorepammo, int
        { 185, 2 },  // game/basenumbers, int
        { 186, 2 },  // game/showbombs, int
        { 187, 2 },  // game/showbombradius, int
        { 188, 2 },  // game/showbombdelay, int
        { 189, 2 },  // game/showminimapobstacles, int
        { 190, 2 },  // game/deadpush, int
        { 191, 2 },  // game/autoauth, int
        { 192, 2 },  // game/smoothmove, int
        { 193, 2 },  // game/smoothdist, int
        { 194, 2 },  // game/slowmosp, int
        { 195, 2 },  // game/spawnwait, int
        { 196, 2 },  // game/hitsound, int
        { 197, 2 },  // game/teamcolorfrags, int
        { 198, 2 },  // game/showmodeinfo, int
        { 199, 2 },  // game/teamcolortext, int
        { 200, 2 },  // game/ammohud, int
        { 201, 2 },  // game/teamcrosshair, int
        { 202, 2 },  // game/hitcrosshair, int
        { 203, 2 },  // game/skill, int
        { 204, 2 },  // game/killsendsp, int
        { 205, 2 },  // game/ragdoll, int
        { 206, 2 },  // game/ragdollmillis, int
        { 207, 2 },  // game/ragdollfade, int
        { 208, 2 },  // game/forceplayermodels, int
        { 209, 2 },  // game/hidedead, int
        { 210, 2 },  // game/testquad, int
        { 211, 2 },  // game/testarmour, int
        { 212, 2 },  // game/hudgun, int
        { 213, 2 },  // game/hudgunsway, int
        { 214, 2 },  // game/teamhudguns, int
        { 215, 2 },  // game/chainsawhudgun, int
        { 216, 2 },  // game/testhudgun, int
        { 217, 1 },  // game/swaystep, float
        { 218, 1 },  // game/swayside, float
        { 219, 1 },  // game/swayup, float
        { 220, 0 },  // game/hudgunsdir, char*
        { 221, 2 },  // game/scoreboard2d, int
        { 222, 2 },  // game/showservinfo, int
        { 223, 2 },  // game/showclientnum, int
        { 224, 2 },  // game/showpj, int
        { 225, 2 },  // game/showping, int
        { 226, 2 },  // game/showspectators, int
        { 227, 2 },  // game/showflags, int
        { 228, 2 },  // game/showfrags, int
        { 229, 2 },  // game/showaccuracy, int
        { 230, 2 },  // game/highlightscore, int
        { 231, 2 },  // game/showconnecting, int
        { 232, 2 },  // game/showscoreboard, int
        { 233, 2 },  // game/maxdebris, int
        { 234, 2 },  // game/maxbarreldebris, int
        { 235, 2 },  // game/blood, int
        { 236, 2 },  // game/muzzleflash, int
        { 237, 2 },  // game/muzzlelight, int
        { 238, 2 },  // game/bombcolliderad, int
        { 239, 2 },  // game/bombbarrier, int
        { 240, 2 },  // game/deathscore, int
        { 241, 2 },  // game/playermodel, int
        { 242, 2 },  // game/testteam, int
        { 243, 2 },  // game/teamskins, int
        { 244, 2 },  // inexor/rendering/screen/scr_w, int
        { 245, 2 },  // inexor/rendering/screen/scr_h, int
        { 246, 2 },  // inexor/rendering/screen/colorbits, int
        { 247, 2 },  // inexor/rendering/screen/depthbits, int
        { 248, 2 },  // inexor/rendering/screen/stencilbits, int
        { 249, 2 },  // inexor/rendering/screen/gamma, int
        { 250, 2 },  // inexor/rendering/screen/vsync, int
        { 251, 2 },  // inexor/rendering/screen/vsynctear, int
        { 252, 2 },  // inexor/rendering/screen/fullscreen, int
        { 253, 2 },  // inexor/sound/soundvol, int
        { 254, 2 },  // inexor/sound/musicvol, int
        { 255, 2 },  // inexor/sound/stereo, int
        { 256, 2 },  // inexor/sound/maxsoundradius, int
        { 257, 2 },  // inexor/sound/maxsoundsatonce, int
        { 258, 2 },  // inexor/sound/dbgsound, int
        { 259, 2 },  // inexor/sound/mumble, int
        { 260, 2 },  // inexor/sound/soundchans, int
        { 261, 2 },  // inexor/sound/soundfreq, int
        { 262, 2 },  // inexor/sound/soundbufferlen, int
        { 263, 2 },  // server/lockmaprotation, int
        { 264, 2 },  // server/maxdemos, int
        { 265, 2 },  // server/maxdemosize, int
        { 266, 2 },  // server/restrictdemos, int
        { 267, 2 },  // server/restrictpausegame, int
        { 268, 2 },  // server/restrictgamespeed, int
        { 269, 2 },  // server/restrictpersistteams, int
        { 270, 0 },  // server/serverdesc, char*
        { 271, 0 },  // server/serverpass, char*
        { 272, 0 },  // server/adminpass, char*
        { 273, 2 },  // server/publicserver, int
        { 274, 0 },  // server/servermotd, char*
        { 275, 2 },  // server/spectatemodifiedmap, int
        { 276, 2 },  // server/ctftkpenalty, int
        { 277, 0 },  // server/serverauth, char*
        { 278, 2 },  // server/modifiedmapspectator, int
        { 279, 2 },  // server/extinfoip, int
        { 280, 2 },  // server/aiman/botlimit, int
        { 281, 2 },  // server/aiman/serverbotbalance, int
        { 282, 2 },  // lerpangle, int
        { 283, 2 },  // lerpsubdiv, int
        { 284, 2 },  // lerpsubdivsize, int
        { 285, 2 },  // dragging, int
        { 286, 2 },  // gridpower, int
        { 287, 2 },  // passthroughsel, int
        { 288, 2 },  // editing, int
        { 289, 2 },  // selectcorners, int
        { 290, 2 },  // hmapedit, int
        { 291, 2 },  // gridlookup, int
        { 292, 2 },  // passthroughcube, int
        { 293, 2 },  // undomegs, int
        { 294, 2 },  // nompedit, int
        { 295, 0 },  // prefabdir, char*
        { 296, 2 },  // brushx, int
        { 297, 2 },  // brushy, int
        { 298, 2 },  // invalidcubeguard, int
        { 299, 2 },  // selectionsurf, int
        { 300, 2 },  // usevdelta, int
        { 301, 2 },  // allfaces, int
        { 302, 2 },  // texguiwidth, int
        { 303, 2 },  // texguiheight, int
        { 304, 2 },  // texguitime, int
        { 305, 2 },  // texgui2d, int
        { 306, 2 },  // debugvbo, int
        { 307, 2 },  // maxvbosize, int
        { 308, 2 },  // filltjoints, int
        { 309, 2 },  // vafacemax, int
        { 310, 2 },  // vafacemin, int
        { 311, 2 },  // vacubesize, int
        { 312, 2 },  // mipvis, int
        { 313, 2 },  // maxmerge, int
        { 314, 2 },  // minface, int
        { 315, 2 },  // dynentsize, int
        { 316, 2 },  // maxroll, int
        { 317, 1 },  // straferoll, float
        { 318, 1 },  // faderoll, float
        { 319, 2 },  // floatspeed, int
        { 320, 2 },  // physinterp, int
        { 321, 2 },  // maxpvsblocker, int
        { 322, 2 },  // pvsleafsize, int
        { 323, 2 },  // pvsthreads, int
        { 324, 2 },  // lockpvs, int
        { 325, 2 },  // usepvs, int
        { 326, 2 },  // usewaterpvs, int
        { 327, 2 },  // ragdolltimestepmin, int
        { 328, 2 },  // ragdolltimestepmax, int
        { 329, 1 },  // ragdollrotfric, float
        { 330, 1 },  // ragdollrotfricstop, float
        { 331, 2 },  // ragdollconstrain, int
        { 332, 1 },  // ragdollbodyfric, float
        { 333, 1 },  // ragdollbodyfricscale, float
        { 334, 1 },  // ragdollwaterfric, float
        { 335, 1 },  // ragdollgroundfric, float
        { 336, 1 },  // ragdollairfric, float
        { 337, 1 },  // ragdollunstick, float
        { 338, 2 },  // ragdollexpireoffset, int
        { 339, 2 },  // ragdollwaterexpireoffset, int
        { 340, 1 },  // ragdolleyesmooth, float
        { 341, 2 },  // ragdolleyesmoothmillis, int
        { 342, 2 },  // glversion, int
        { 343, 2 },  // glslversion, int
        { 344, 2 },  // ati_skybox_bug, int
        { 345, 2 },  // ati_minmax_bug, int
        { 346, 2 },  // ati_cubemap_bug, int
        { 347, 2 },  // intel_vertexarray_bug, int
        { 348, 2 },  // intel_mapbufferrange_bug, int
        { 349, 2 },  // minimizetcusage, int
        { 350, 2 },  // useubo, int
        { 351, 2 },  // usetexcompress, int
        { 352, 2 },  // rtscissor, int
        { 353, 2 },  // blurtile, int
        { 354, 2 },  // rtsharefb, int
        { 355, 2 },  // dbgexts, int
        { 356, 2 },  // wireframe, int
        { 357, 2 },  // zoominvel, int
        { 358, 2 },  // zoomoutvel, int
        { 359, 2 },  // zoomfov, int
        { 360, 2 },  // fov, int
        { 361, 2 },  // followfov, int
        { 362, 2 },  // avatarzoomfov, int
        { 363, 2 },  // avatarfov, int
        { 364, 1 },  // avatardepth, float
        { 365, 1 },  // forceaspect, float
        { 366, 2 },  // zoom, int
        { 367, 1 },  // zoomsens, float
        { 368, 1 },  // zoomaccel, float
        { 369, 2 },  // zoomautosens, int
        { 370, 1 },  // sensitivity, float
        { 371, 1 },  // sensitivityscale, float
        { 372, 2 },  // invmouse, int
        { 373, 1 },  // mouseaccel, float
        { 374, 2 },  // thirdperson, int
        { 375, 1 },  // thirdpersondistance, float
        { 376, 1 },  // thirdpersonup, float
        { 377, 1 },  // thirdpersonside, float
        { 378, 1 },  // nearplane, float
        { 379, 2 },  // reflectclip, int
        { 380, 2 },  // reflectclipavatar, int
        { 381, 1 },  // polygonoffsetfactor, float
        { 382, 1 },  // polygonoffsetunits, float
        { 383, 1 },  // depthoffset, float
        { 384, 2 },  // fog, int
        { 385, 2 },  // fogcolour, int
        { 386, 2 },  // skyboxglare, int
        { 387, 2 },  // reflectmms, int
        { 388, 2 },  // refractsky, int
        { 389, 2 },  // modelpreviewfov, int
        { 390, 2 },  // modelpreviewpitch, int
        { 391, 2 },  // minimapheight, int
        { 392, 2 },  // minimapcolour, int
        { 393, 2 },  // minimapclip, int
        { 394, 2 },  // minimapsize, int
        { 395, 2 },  // motionblur, int
        { 396, 2 },  // motionblurmillis, int
        { 397, 1 },  // motionblurscale, float
        { 398, 2 },  // usedamagecompass, int
        { 399, 2 },  // damagecompassfade, int
        { 400, 2 },  // damagecompasssize, int
        { 401, 2 },  // damagecompassalpha, int
        { 402, 2 },  // damagecompassmin, int
        { 403, 2 },  // damagecompassmax, int
        { 404, 2 },  // damagescreen, int
        { 405, 2 },  // damagescreenfactor, int
        { 406, 2 },  // damagescreenalpha, int
        { 407, 2 },  // damagescreenfade, int
        { 408, 2 },  // damagescreenmin, int
        { 409, 2 },  // damagescreenmax, int
        { 410, 2 },  // hidestats, int
        { 411, 2 },  // hidehud, int
        { 412, 2 },  // crosshairsize, int
        { 413, 2 },  // cursorsize, int
        { 414, 2 },  // crosshairfx, int
        { 415, 2 },  // crosshaircolors, int
        { 416, 0 },  // crosshairdir, char*
        { 417, 0 },  // cursor, char*
        { 418, 2 },  // wallclock, int
        { 419, 2 },  // wallclock24, int
        { 420, 2 },  // wallclocksecs, int
        { 421, 2 },  // showfps, int
        { 422, 2 },  // showfpsrange, int
        { 423, 2 },  // showeditstats, int
        { 424, 2 },  // statrate, int
        { 425, 1 },  // conscale, float
        { 426, 0 },  // modeldir, char*
        { 427, 2 },  // oqdynent, int
        { 428, 2 },  // animationinterpolationtime, int
        { 429, 2 },  // showboundingbox, int
        { 430, 2 },  // maxmodelradiusdistance, int
        { 431, 2 },  // animoverride, int
        { 432, 2 },  // testanims, int
        { 433, 2 },  // testpitch, int
        { 434, 2 },  // particlesize, int
        { 435, 2 },  // emitmillis, int
        { 436, 2 },  // showparticles, int
        { 437, 2 },  // cullparticles, int
        { 438, 2 },  // replayparticles, int
        { 439, 2 },  // seedmillis, int
        { 440, 2 },  // dbgpcull, int
        { 441, 2 },  // dbgpseed, int
        { 442, 2 },  // outlinemeters, int
        { 443, 2 },  // maxparticles, int
        { 444, 2 },  // fewparticles, int
        { 445, 2 },  // particleglare, int
        { 446, 2 },  // dbgparts, int
        { 447, 2 },  // maxparticledistance, int
        { 448, 2 },  // maxtrail, int
        { 449, 2 },  // particletext, int
        { 450, 2 },  // maxparticletextdistance, int
        { 451, 0 },  // skybox, char*
        { 452, 2 },  // skyboxcolour, int
        { 453, 1 },  // spinsky, float
        { 454, 2 },  // yawsky, int
        { 455, 0 },  // cloudbox, char*
        { 456, 2 },  // cloudboxcolour, int
        { 457, 1 },  // cloudboxalpha, float
        { 458, 1 },  // spinclouds, float
        { 459, 2 },  // yawclouds, int
        { 460, 1 },  // cloudclip, float
        { 461, 0 },  // cloudlayer, char*
        { 462, 1 },  // cloudoffsetx, float
        { 463, 1 },  // cloudoffsety, float
        { 464, 1 },  // cloudscrollx, float
        { 465, 1 },  // cloudscrolly, float
        { 466, 1 },  // cloudscale, float
        { 467, 1 },  // spincloudlayer, float
        { 468, 2 },  // yawcloudlayer, int
        { 469, 1 },  // cloudheight, float
        { 470, 1 },  // cloudfade, float
        { 471, 1 },  // cloudalpha, float
        { 472, 2 },  // cloudsubdiv, int
        { 473, 2 },  // cloudcolour, int
        { 474, 1 },  // fogdomeheight, float
        { 475, 1 },  // fogdomemin, float
        { 476, 1 },  // fogdomemax, float
        { 477, 2 },  // fogdomecap, int
        { 478, 1 },  // fogdomeclip, float
        { 479, 2 },  // fogdomecolour, int
        { 480, 2 },  // sparklyfix, int
        { 481, 2 },  // showsky, int
        { 482, 2 },  // clipsky, int
        { 483, 2 },  // clampsky, int
        { 484, 2 },  // fogdomeclouds, int
        { 485, 2 },  // useskytexture, int
        { 486, 2 },  // oqfrags, int
        { 487, 2 },  // oqwait, int
        { 488, 2 },  // oqmm, int
        { 489, 2 },  // outline, int
        { 490, 2 },  // outlinecolour, int
        { 491, 2 },  // dtoutline, int
        { 492, 2 },  // blendbrushcolor, int
        { 493, 2 },  // oqdist, int
        { 494, 2 },  // zpass, int
        { 495, 2 },  // glowpass, int
        { 496, 2 },  // envpass, int
        { 497, 2 },  // batchgeom, int
        { 498, 0 },  // causticdir, char*
        { 499, 2 },  // causticscale, int
        { 500, 2 },  // causticmillis, int
        { 501, 2 },  // caustics, int
        { 502, 2 },  // oqgeom, int
        { 503, 2 },  // compresspng, int
        { 504, 2 },  // compresstga, int
        { 505, 0 },  // screenshotdir, char*
        { 506, 2 },  // screenshotformat, int
        { 507, 2 },  // searchlan, int
        { 508, 2 },  // servpingrate, int
        { 509, 2 },  // servpingdecay, int
        { 510, 2 },  // maxservpings, int
        { 511, 2 },  // autosortservers, int
        { 512, 2 },  // autoupdateservers, int
        { 513, 2 },  // reservevpparams, int
        { 514, 2 },  // maxvsuniforms, int
        { 515, 2 },  // maxfsuniforms, int
        { 516, 2 },  // maxvaryings, int
        { 517, 2 },  // dbgshader, int
        { 518, 2 },  // dbgubo, int
        { 519, 2 },  // shaderprecision, int
        { 520, 2 },  // defershaders, int
        { 521, 2 },  // shaderdetail, int
        { 522, 2 },  // shadowmap, int
        { 523, 2 },  // shadowmapsize, int
        { 524, 2 },  // shadowmapradius, int
        { 525, 2 },  // shadowmapheight, int
        { 526, 2 },  // shadowmapdist, int
        { 527, 2 },  // fpshadowmap, int
        { 528, 2 },  // shadowmapprecision, int
        { 529, 2 },  // shadowmapambient, int
        { 530, 2 },  // shadowmapintensity, int
        { 531, 2 },  // blurshadowmap, int
        { 532, 2 },  // blursmsigma, int
        { 533, 2 },  // shadowmapcasters, int
        { 534, 2 },  // shadowmapangle, int
        { 535, 2 },  // shadowmapbias, int
        { 536, 2 },  // shadowmappeelbias, int
        { 537, 2 },  // smdepthpeel, int
        { 538, 2 },  // smoothshadowmappeel, int
        { 539, 2 },  // debugsm, int
        { 540, 2 },  // gpuskel, int
        { 541, 2 },  // maxskelanimdata, int
        { 542, 2 },  // testtags, int
        { 543, 2 },  // autocompactvslots, int
        { 544, 2 },  // dbggz, int
        { 545, 2 },  // hwtexsize, int
        { 546, 2 },  // hwcubetexsize, int
        { 547, 2 },  // hwmaxaniso, int
        { 548, 2 },  // maxtexsize, int
        { 549, 2 },  // reducefilter, int
        { 550, 2 },  // texreduce, int
        { 551, 2 },  // trilinear, int
        { 552, 2 },  // bilinear, int
        { 553, 2 },  // aniso, int
        { 554, 2 },  // texcompress, int
        { 555, 2 },  // texcompressquality, int
        { 556, 2 },  // usenp2, int
        { 557, 2 },  // usedds, int
        { 558, 2 },  // scaledds, int
        { 559, 2 },  // waterreflect, int
        { 560, 2 },  // waterrefract, int
        { 561, 2 },  // waterenvmap, int
        { 562, 2 },  // waterfallrefract, int
        { 563, 2 },  // watersubdiv, int
        { 564, 2 },  // waterlod, int
        { 565, 2 },  // vertwater, int
        { 566, 2 },  // reflectdist, int
        { 567, 2 },  // watercolour, int
        { 568, 2 },  // waterfog, int
        { 569, 2 },  // waterspec, int
        { 570, 2 },  // waterfallcolour, int
        { 571, 2 },  // water2colour, int
        { 572, 2 },  // water2fog, int
        { 573, 2 },  // water2spec, int
        { 574, 2 },  // water2fallcolour, int
        { 575, 2 },  // water3colour, int
        { 576, 2 },  // water3fog, int
        { 577, 2 },  // water3spec, int
        { 578, 2 },  // water3fallcolour, int
        { 579, 2 },  // water4colour, int
        { 580, 2 },  // water4fog, int
        { 581, 2 },  // water4spec, int
        { 582, 2 },  // water4fallcolour, int
        { 583, 2 },  // lavacolour, int
        { 584, 2 },  // lavafog, int
        { 585, 2 },  // lava2colour, int
        { 586, 2 },  // lava2fog, int
        { 587, 2 },  // lava3colour, int
        { 588, 2 },  // lava3fog, int
        { 589, 2 },  // lava4colour, int
        { 590, 2 },  // lava4fog, int
        { 591, 2 },  // oqwater, int
        { 592, 2 },  // waterfade, int
        { 593, 2 },  // reflectsize, int
        { 594, 2 },  // maxreflect, int
        { 595, 2 },  // maskreflect, int
        { 596, 2 },  // reflectscissor, int
        { 597, 2 },  // reflectvfc, int
        { 598, 2 },  // refractclear, int
        { 599, 2 },  // savebak, int
        { 600, 2 },  // dbgvars, int
        { 601, 2 },  // mapversion, int
        { 602, 2 },  // worldscale, int
        { 603, 2 },  // worldsize, int
        { 604, 0 },  // maptitle, char*
        { 605, 2 },  // octaentsize, int
        { 606, 2 },  // entselradius, int
        { 607, 2 },  // entediting, int
        { 608, 2 },  // attachradius, int
        { 609, 2 },  // entselsnap, int
        { 610, 2 },  // entmovingshadow, int
        { 611, 2 },  // showentradius, int
        { 612, 2 },  // entitysurf, int
        { 613, 2 },  // entautoviewdist, int
        { 614, 2 },  // entdrop, int
        { 615, 2 },  // dbgzip, int
    
    };

} client_treedata;

} } // namespace inexor::rpc
