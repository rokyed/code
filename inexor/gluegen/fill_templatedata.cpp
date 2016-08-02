
#include <vector>
#include <string>
#include <sstream>

#include <boost/algorithm/string/regex.hpp>

#include "inexor/gluegen/fill_templatedata.hpp"
#include "inexor/gluegen/tree.hpp"

using namespace inexor::rpc::gluegen;

using std::string;
using std::vector;

/// Join the entrys of a vector|sthelsewithranges into a string, using 'd' as the seperator between the parts.
template<typename SinglePassRange, typename Delim>
string join_to_str(SinglePassRange r, Delim d)
{
    std::stringstream s;
    bool first = true;
    for(auto &e : r)
    {
        if(first)
            first = false;
        else
            s << d;
        s << e;
    }
    return s.str();
}

/// C++ equivalent of strtok, tokenizes the input string based on the occurences of delimiter.
/// @param delimiter is actually a boost::regex, so could be used as such!
/// Note: make this a template if needed.
vector<string> split_by_delimter(string input, string delimiter)
{
    using boost::regex;
    using boost::split_regex;

    vector<string> ns;
    split_regex(ns, input, regex(delimiter));
    return std::move(ns);
}
static const char *alpha[] =
{
    "guiautotab",
    "guiclicktab",
    "guifadein",
    "guipushdist",
    "guisens",
    "useguifollow",
    "usegui2d",
    "blendpaintmode",
    "paintblendmapdelay",
    "paintblendmapinterval",
    "showblobs",
    "blobintensity",
    "blobheight",
    "blobfadelow",
    "blobfadehigh",
    "blobmargin",
    "dbgblob",
    "blobstattris",
    "blobdyntris",
    "rate",
    "throttle_interval",
    "throttle_accel",
    "throttle_decel",
    "connectname",
    "connectport",
    "dbgalias",
    "maxcon",
    "confading",
    "fullconsole",
    "consize",
    "miniconsize",
    "miniconwidth",
    "confade",
    "miniconfade",
    "fullconsize",
    "confilter",
    "fullconfilter",
    "miniconfilter",
    "maxhistory",
    "maxdecaltris",
    "decalfade",
    "dbgdec",
    "showdecals",
    "maxdecaldistance",
    "maxdynlights",
    "dynlightdist",
    "glaresize",
    "glare",
    "blurglare",
    "blurglaresigma",
    "debugglare",
    "glarescale",
    "grass",
    "dbggrass",
    "grassdist",
    "grasstaper",
    "grassstep",
    "grassheight",
    "grassanimmillis",
    "grassanimscale",
    "grassscale",
    "grassalpha",
    "lightprecision",
    "lighterror",
    "bumperror",
    "lightlod",
    "sunlightyaw",
    "sunlightpitch",
    "skytexturelight",
    "lmshadows_",
    "lmaa_",
    "lerptjoints_",
    "lmao_",
    "lightcompress",
    "ambientocclusion",
    "ambientocclusionradius",
    "debugao",
    "blurlms",
    "blurskylight",
    "edgetolerance",
    "adaptivesample",
    "lightcachesize",
    "lightthreads",
    "patchnormals",
    "fullbright",
    "fullbrightlevel",
    "roundlightmaptex",
    "batchlightmaps",
    "inexor::rendering::screen::scr_w",
    "inexor::rendering::screen::scr_h",
    "inexor::rendering::screen::colorbits",
    "inexor::rendering::screen::depthbits",
    "inexor::rendering::screen::stencilbits",
    "inexor::rendering::screen::vsync",
    "inexor::rendering::screen::vsynctear",
    "fsaa",
    "background",
    "logo",
    "userelativemouse",
    "inexor::rendering::screen::fullscreen",
    "inexor::rendering::screen::gamma",
    "menufps",
    "maxfps",
    "clockerror",
    "clockfix",
    "numcpus",
    "optmats",
    "showmat",
    "glassenv",
    "waterfallenv",
    "menudistance",
    "menuautoclose",
    "applydialog",
    "mainmenu",
    "dbgmovie",
    "movieaccelblit",
    "movieaccelyuv",
    "movieaccel",
    "moviesync",
    "movieminquality",
    "moview",
    "movieh",
    "moviefps",
    "moviesound",
    "lerpangle",
    "lerpsubdiv",
    "lerpsubdivsize",
    "mipvis",
    "maxmerge",
    "minface",
    "dragging",
    "gridpower",
    "passthroughsel",
    "editing",
    "selectcorners",
    "hmapedit",
    "gridlookup",
    "passthroughcube",
    "undomegs",
    "nompedit",
    "prefabdir",
    "brushx",
    "brushy",
    "invalidcubeguard",
    "selectionsurf",
    "usevdelta",
    "allfaces",
    "texguiwidth",
    "texguiheight",
    "texguitime",
    "texgui2d",
    "debugvbo",
    "maxvbosize",
    "filltjoints",
    "vafacemax",
    "vafacemin",
    "vacubesize",
    "dynentsize",
    "maxroll",
    "straferoll",
    "faderoll",
    "floatspeed",
    "physinterp",
    "maxpvsblocker",
    "pvsleafsize",
    "pvsthreads",
    "lockpvs",
    "usepvs",
    "usewaterpvs",
    "glversion",
    "glslversion",
    "ati_skybox_bug",
    "ati_minmax_bug",
    "ati_cubemap_bug",
    "intel_vertexarray_bug",
    "intel_mapbufferrange_bug",
    "minimizetcusage",
    "useubo",
    "usetexcompress",
    "rtscissor",
    "blurtile",
    "rtsharefb",
    "dbgexts",
    "wireframe",
    "zoominvel",
    "zoomoutvel",
    "zoomfov",
    "fov",
    "followfov",
    "avatarzoomfov",
    "avatarfov",
    "avatardepth",
    "forceaspect",
    "zoom",
    "zoomsens",
    "zoomaccel",
    "zoomautosens",
    "sensitivity",
    "sensitivityscale",
    "invmouse",
    "mouseaccel",
    "thirdperson",
    "thirdpersondistance",
    "thirdpersonup",
    "thirdpersonside",
    "nearplane",
    "reflectclip",
    "reflectclipavatar",
    "polygonoffsetfactor",
    "polygonoffsetunits",
    "depthoffset",
    "fog",
    "skyboxglare",
    "reflectmms",
    "refractsky",
    "modelpreviewfov",
    "modelpreviewpitch",
    "minimapheight",
    "minimapclip",
    "minimapsize",
    "motionblur",
    "motionblurmillis",
    "motionblurscale",
    "usedamagecompass",
    "damagecompassfade",
    "damagecompasssize",
    "damagecompassalpha",
    "damagecompassmin",
    "damagecompassmax",
    "damagescreen",
    "damagescreenfactor",
    "damagescreenalpha",
    "damagescreenfade",
    "damagescreenmin",
    "damagescreenmax",
    "hidestats",
    "hidehud",
    "crosshairsize",
    "cursorsize",
    "crosshairfx",
    "crosshaircolors",
    "crosshairdir",
    "cursor",
    "wallclock",
    "wallclock24",
    "wallclocksecs",
    "showfps",
    "showfpsrange",
    "showeditstats",
    "statrate",
    "conscale",
    "modeldir",
    "oqdynent",
    "animationinterpolationtime",
    "ragdolltimestepmin",
    "ragdolltimestepmax",
    "ragdollrotfric",
    "ragdollrotfricstop",
    "ragdollconstrain",
    "ragdollbodyfric",
    "ragdollbodyfricscale",
    "ragdollwaterfric",
    "ragdollgroundfric",
    "ragdollairfric",
    "ragdollunstick",
    "ragdollexpireoffset",
    "ragdollwaterexpireoffset",
    "ragdolleyesmooth",
    "ragdolleyesmoothmillis",
    "envmapmodels",
    "bumpmodels",
    "fullbrightmodels",
    "gpuskel",
    "maxskelanimdata",
    "testtags",
    "showboundingbox",
    "maxmodelradiusdistance",
    "animoverride",
    "testanims",
    "testpitch",
    "particlesize",
    "emitmillis",
    "showparticles",
    "cullparticles",
    "replayparticles",
    "seedmillis",
    "dbgpcull",
    "dbgpseed",
    "outlinemeters",
    "depthfxfpscale",
    "depthfxscale",
    "depthfxblend",
    "depthfxpartblend",
    "depthfxmargin",
    "depthfxbias",
    "fpdepthfx",
    "depthfxemuprecision",
    "depthfxsize",
    "depthfx",
    "depthfxparts",
    "blurdepthfx",
    "blurdepthfxsigma",
    "depthfxscissor",
    "debugdepthfx",
    "flarelights",
    "flarecutoff",
    "flaresize",
    "lnjittermillis",
    "lnjitterradius",
    "lnjitterscale",
    "lnscrollmillis",
    "lnscrollscale",
    "lnblendpower",
    "maxparticles",
    "fewparticles",
    "particleglare",
    "dbgparts",
    "maxparticledistance",
    "maxtrail",
    "particletext",
    "maxparticletextdistance",
    "skybox",
    "skyboxcolour",
    "spinsky",
    "yawsky",
    "cloudbox",
    "cloudboxcolour",
    "cloudboxalpha",
    "spinclouds",
    "yawclouds",
    "cloudclip",
    "cloudlayer",
    "cloudoffsetx",
    "cloudoffsety",
    "cloudscrollx",
    "cloudscrolly",
    "cloudscale",
    "spincloudlayer",
    "yawcloudlayer",
    "cloudheight",
    "cloudfade",
    "cloudalpha",
    "cloudsubdiv",
    "cloudcolour",
    "fogdomeheight",
    "fogdomemin",
    "fogdomemax",
    "fogdomecap",
    "fogdomeclip",
    "sparklyfix",
    "showsky",
    "clipsky",
    "clampsky",
    "fogdomeclouds",
    "useskytexture",
    "oqfrags",
    "oqwait",
    "oqmm",
    "outline",
    "outlinecolour",
    "dtoutline",
    "blendbrushcolor",
    "oqdist",
    "zpass",
    "glowpass",
    "envpass",
    "batchgeom",
    "causticdir",
    "causticscale",
    "causticmillis",
    "caustics",
    "oqgeom",
    "maxclients",
    "maxdupclients",
    "allowupdatemaster",
    "mastername",
    "masterport",
    "serveruprate",
    "serverip",
    "serverport",
    "searchlan",
    "servpingrate",
    "servpingdecay",
    "maxservpings",
    "autosortservers",
    "autoupdateservers",
    "reservevpparams",
    "maxvsuniforms",
    "maxfsuniforms",
    "maxvaryings",
    "dbgshader",
    "dbgubo",
    "shaderprecision",
    "defershaders",
    "shaderdetail",
    "shadowmap",
    "shadowmapsize",
    "shadowmapradius",
    "shadowmapheight",
    "shadowmapdist",
    "fpshadowmap",
    "shadowmapprecision",
    "shadowmapintensity",
    "blurshadowmap",
    "blursmsigma",
    "shadowmapangle",
    "shadowmapbias",
    "shadowmappeelbias",
    "smdepthpeel",
    "smoothshadowmappeel",
    "debugsm",
    "inexor::sound::soundvol",
    "inexor::sound::musicvol",
    "inexor::sound::soundchans",
    "inexor::sound::soundfreq",
    "inexor::sound::soundbufferlen",
    "inexor::sound::stereo",
    "inexor::sound::maxsoundradius",
    "inexor::sound::maxsoundsatonce",
    "inexor::sound::dbgsound",
    "inexor::sound::mumble",
    "waterreflect",
    "waterrefract",
    "waterenvmap",
    "waterfallrefract",
    "watersubdiv",
    "waterlod",
    "vertwater",
    "reflectdist",
    "waterfog",
    "waterspec",
    "water2fog",
    "water2spec",
    "water3fog",
    "water3spec",
    "water4fog",
    "water4spec",
    "lavafog",
    "lava2fog",
    "lava3fog",
    "lava4fog",
    "oqwater",
    "waterfade",
    "reflectsize",
    "maxreflect",
    "maskreflect",
    "reflectscissor",
    "reflectvfc",
    "refractclear",
    "mapversion",
    "worldscale",
    "worldsize",
    "maptitle",
    "octaentsize",
    "entselradius",
    "entediting",
    "attachradius",
    "entselsnap",
    "entmovingshadow",
    "showentradius",
    "entitysurf",
    "entautoviewdist",
    "entdrop",
    "savebak",
    "dbgvars",
    "mapdir",
    "texturedir",
    "skyboxdir",
    "interfacedir",
    "icondir",
    "sounddir",
    "musicdir",
    "ai::aidebug",
    "ai::aiforcegun",
    "ai::showwaypoints",
    "ai::showwaypointsradius",
    "game::minradarscale",
    "game::maxradarscale",
    "game::radarteammates",
    "game::minimapalpha",
    "game::radardir",
    "game::capturetether",
    "game::autorepammo",
    "game::basenumbers",
    "game::showbombs",
    "game::showbombradius",
    "game::showbombdelay",
    "game::showminimapobstacles",
    "game::deadpush",
    "game::autoauth",
    "entities::triggerstate",
    "game::smoothmove",
    "game::smoothdist",
    "game::slowmosp",
    "game::spawnwait",
    "game::hitsound",
    "game::deathscore",
    "game::teamcolorfrags",
    "game::showmodeinfo",
    "game::teamcolortext",
    "game::ammohud",
    "game::teamcrosshair",
    "game::hitcrosshair",
    "game::skill",
    "game::killsendsp",
    "game::ragdoll",
    "game::ragdollmillis",
    "game::ragdollfade",
    "game::playermodel",
    "game::forceplayermodels",
    "game::hidedead",
    "game::testquad",
    "game::testarmour",
    "game::testteam",
    "game::teamskins",
    "game::hudgun",
    "game::hudgunsway",
    "game::teamhudguns",
    "game::chainsawhudgun",
    "game::testhudgun",
    "game::swaystep",
    "game::swayside",
    "game::swayup",
    "game::hudgunsdir",
    "game::scoreboard2d",
    "game::showservinfo",
    "game::showclientnum",
    "game::showpj",
    "game::showping",
    "game::showspectators",
    "game::showflags",
    "game::showfrags",
    "game::showaccuracy",
    "game::highlightscore",
    "game::showconnecting",
    "game::showscoreboard",
    "server::lockmaprotation",
    "server::maxdemos",
    "server::maxdemosize",
    "server::restrictdemos",
    "server::restrictpausegame",
    "server::restrictgamespeed",
    "server::restrictpersistteams",
    "server::serverdesc",
    "server::serverpass",
    "server::adminpass",
    "server::publicserver",
    "server::servermotd",
    "server::spectatemodifiedmap",
    "server::ctftkpenalty",
    "server::serverauth",
    "server::modifiedmapspectator",
    "server::extinfoip",
    "server::aiman::botlimit",
    "server::aiman::serverbotbalance",
    "ai::dropwaypoints",
    "game::maxdebris",
    "game::maxbarreldebris",
    "game::blood",
    "game::muzzleflash",
    "game::muzzlelight",
    "game::bombcolliderad",
    "game::bombbarrier",
    "dbggz",
    "dbgzip",
    "dbgdds",
    "envmapsize",
    "envmapradius",
    "aaenvmap",
    "compresspng",
    "compresstga",
    "screenshotformat",
    "screenshotdir",
    "autocompactvslots",
    "hwtexsize",
    "hwcubetexsize",
    "hwmaxaniso",
    "maxtexsize",
    "reducefilter",
    "texreduce",
    "trilinear",
    "bilinear",
    "aniso",
    "texcompress",
    "texcompressquality",
    "usenp2",
    "usedds",
    "scaledds"
};
#include <unordered_set>
TemplateData fill_templatedata(vector<ShTreeNode> &tree, const string &ns)
{
    TemplateData tmpldata{TemplateData::Type::Object};

    tmpldata["file_comment"] =  "// This file gets generated!\n"
        "// Do not modify it directly but its corresponding template file instead!";

    // namespace string -> protobuf syntax: replace :: with .
    vector<string> ns_list(split_by_delimter(ns, "::"));
    const string &proto_pkg = join_to_str(ns_list, '.');
    tmpldata["package"] = proto_pkg;
    tmpldata["namespace"] = ns;

    TemplateData sharedvars{TemplateData::Type::List};
    int index = 1;
    for(auto node : tree)
    {
        TemplateData curvariable{TemplateData::Type::Object};
        curvariable["type_protobuf"] = node.get_type_protobuf();
        curvariable["type_cpp_primitive"] = node.get_type_cpp_primitive();
        curvariable["index"] = std::to_string(index++);
        curvariable["name_unique"] = node.get_name_unique();
        curvariable["path"] = node.get_path();
        curvariable["cpp_name"] = node.get_name_cpp_full();

        vector<string> ns(split_by_delimter(node.get_name_cpp_full(), "::"));
        curvariable["cpp_raw_name"] = ns.back();

        ns.pop_back(); // remove the raw function name
        TemplateData namespace_sep_open{TemplateData::LambdaType{
            [ns](const string&)
        {
            std::stringstream ss;
            for(auto &tok : ns)
            {
                if(tok.empty())continue;
                ss << "namespace ";
                ss << tok;
                ss << " { ";
            }
            return ss.str();
        }}};

        TemplateData namespace_sep_close{TemplateData::LambdaType{
            [ns](const std::string&)
        {
            std::stringstream ss;
            for(auto &tok : ns)
            {
                if(tok.empty())continue;
                ss << " }";
            }
            return ss.str();
        }}};

        curvariable["namespace_sep_open"] = namespace_sep_open;
        curvariable["namespace_sep_close"] = namespace_sep_close;

        sharedvars << curvariable;
    }
    tmpldata["shared_vars"] = sharedvars;

    TemplateData old_list{TemplateData::Type::List};
    std::vector<std::string> all_old;
    for(int i = 0; i < 588; i++)
    {
        all_old.push_back(alpha[i]);
    }
    std::sort(all_old.begin(), all_old.end());
    for(auto it : all_old)
    {
        TemplateData curvariable{TemplateData::Type::Object};
        curvariable["n"] = it;
        old_list << curvariable;
    }
    tmpldata["vergleich_liste_alt"] = old_list;


    TemplateData new_list{TemplateData::Type::List};
    std::vector<std::string> all_new;
    for(auto node : tree)
    {
        all_new.push_back(node.get_name_cpp_full());
    }
    std::sort(all_new.begin(), all_new.end());

    for(auto it : all_new)
    {
        TemplateData curvariable{TemplateData::Type::Object};
        curvariable["n"] = it;
        new_list << curvariable;
    }
    tmpldata["vergleich_liste_neu"] = new_list;
    return tmpldata;
}

