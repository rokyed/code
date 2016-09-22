#ifndef INEXOR_VSCRIPT_OPERATOR_DECREASE_HEADER
#define INEXOR_VSCRIPT_OPERATOR_DECREASE_HEADER

#include "inexor/entity/EntitySystemBase.hpp"
#include "inexor/entity/domain/graph/EntityFunction.hpp"
#include "inexor/entity/domain/graph/EntityInstance.hpp"
#include "inexor/vscript/model/VScriptModel.hpp"
#include "inexor/util/Logging.hpp"

using namespace inexor::entity;

namespace inexor {
namespace vscript {

    class DecreaseInteger : public EntityFunction
    {
        public:

            DecreaseInteger();
            virtual ~DecreaseInteger();

            // The activator function (source, target, relationship from source to target)
            void Execute(TimeStep time_step, std::shared_ptr<EntityInstance> activator_instance, std::shared_ptr<EntityInstance> integer_memory_instance, std::shared_ptr<RelationshipInstance> activates);

    };

}
}

#endif /* INEXOR_VSCRIPT_OPERATOR_DECREASE_HEADER */
