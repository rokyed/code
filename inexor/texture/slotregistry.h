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

#include "inexor/engine/engine.h" //todo json outside engine

namespace inexor {
namespace texture {
    /// A set of Slots to make threaded loading possible.
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

        void cleanup()
        {
            loopv(slots) slots[i]->cleanup();
            loopv(vslots) vslots[i]->cleanup();
            loopi((MATF_VOLUME | MATF_INDEX) + 1) materialslots[i].cleanup();
        }

        /// Resets all textures from the slots-stack.
        /// @param first: the texturepos from whereon you want to reset
        /// @param num: the number of slots you want to reset from thereon. All if 0
        /// @example reset(0, 40); resets the first 40 textures
        void reset(int first, int num = 0);

        /// Print a list of all included **slots**, its textures and the amount of VSlots they got.
        void echo();

        /// Export textureset to json file.
        void write(const char *filename);


        // Other:
        void loadlayermasks()
        {
            loopv(slots) slots[i]->loadlayermask();
        }
    };

}   // namespace texture
}   // namespace inexor

#endif // INEXOR_TEX_SLOTREGISTRY_H
