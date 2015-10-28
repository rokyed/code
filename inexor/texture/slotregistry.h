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

        /// Adds a texture to the set from a JSON (Object).
        void addslot(JSON *j);

        /// Adds a texture to the set from a json-file.
        void addslot(const char *filename);

        /// Loads all slots to memory.
        void load();

        void echo()
        {
            loopv(slots) {
                loopvk(slots[i]->sts) conoutf("tex %d.%d: %s", i, k, slots[i]->sts[k].name);
            }
        }

        /// Export textureset to json file.
        void write(const char *filename);
    };

    extern slotregistry *newslotregistry(JSON *parent);
    extern bool loadset(const char *name);

}   // namespace texture
}   // namespace inexor

#endif // INEXOR_TEX_SLOTREGISTRY_H
