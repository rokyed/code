/// @file slotsets are used to load texture-slots asynchronously.
///

///// GENERAL:
///
/// Inexors routine of loading and storing ingame-textures depends on 3 structures:
/// VSlot       - A Structure holding general info about scale, shadersettings, rotation, ..
/// Slot        - Basicly thats a "Texture" as you would find it ingame in the texturebrowser.
///               It consists of minimum 1 image (the diffuse-file) and various others providing special info (height,..).
///               Every VSlot has a Slot.
/// slotregistry  - A Set of textures/Slots to make loading easier and asynchronous.
///
/// The currently visible stack of ingame-textures (Slots) is vector<Slot *> slots.

#ifndef INEXOR_TEX_SLOTREGISTRY_H
#define INEXOR_TEX_SLOTREGISTRY_H

#include "inexor/engine/engine.h"

namespace inexor {
namespace texture {

    /// A set of Slots to be bundled within a map.
    class slotregistry
    {
    private:

    public:
        /// All included Slots.
        vector<Slot *>slots;

        /// All child vslots (derived from slots).
        vector<VSlot *>vslots;

        /// All given material slots (beeing a merged vslot and slot)
        MSlot materialslots[(MATF_VOLUME | MATF_INDEX) + 1];

        slotregistry(JSON *j = NULL);
        slotregistry(const char *filename, bool load);

        /// Adds a texture to the set from a JSON (Object).
        void addslot(JSON *j);

        /// Adds a texture to the set from a json-file.
        void addslot(const char *filename);

        /// Loads all slots to memory.
        void load();

        /// To be useable the used shaders have to be linked to the slots/vslots/matslots.
        /// TODO Refractor when refractoring the shader stuff
        void linkshaders();

        /// Cleanup all data: Unload all textures and unlink the shaders.
        /// (textures beeing preserverd in memory and the textureregistry though)
        void cleanup()
        {
            loopv(slots) slots[i]->cleanup();
            loopv(vslots) vslots[i]->cleanup();
            loopi((MATF_VOLUME | MATF_INDEX) + 1) materialslots[i].cleanup();
        }

        /// Resets all textures from the slots-stack.
        /// @param first: the texturepos from whereon you want to reset
        /// @param num: the number of slots you want to reset from thereon. All if 0
        /// @example texturereset(0, 40); resets the first 40 textures
        void texturereset(int first, int num = 0);

        /// Print a list of all included **slots**, its textures and the amount of VSlots they got.
        void echo();

        /// Export textureset to json file.
        void write(const char *filename);


        // Other:
        void loadlayermasks()
        {
            loopv(slots) slots[i]->loadlayermask();
        }

        /// Resets the material stack back to its initial state.
        void materialreset();

        /// Put the vslot (with the given index number) in a network package.
        void serializevslot(vector<uchar> &buf, int index);

        /// Save all included virtual slots (vslots) to the old ogz Cube2 mapformat.
        /// @param f (file) stream
        /// @param numvslots the number of vslots which will be written to the file stream
        void savetoogz(stream *f, int numvslots);

        /// Load all vslots from an (old) ogz mapfile.
        /// @param f (file) stream
        /// @param numvslots the number of vslots to read
        void parsefromogz(stream *f, int numvslots);
    };

    extern slotregistry *getcurslotreg();
    extern void switchcurslotreg();
}   // namespace texture
}   // namespace inexor

extern int numcurslots();

extern bool hasslot(int index);
extern bool hasvslot(int index);

extern Slot &lookupslot(int slot, bool load = true);
extern VSlot &lookupvslot(int slot, bool load = true);
extern MSlot &lookupmaterialslot(int slot, bool load = true);


#endif // INEXOR_TEX_SLOTREGISTRY_H
