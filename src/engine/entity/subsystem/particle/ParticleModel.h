/*
 * ParticleModel.h
 *
 *  Created on: 01.02.2015
 *      Author: aschaeffer
 */

#ifndef SRC_ENGINE_ENTITY_SUBSYSTEM_PARTICLE_PARTICLEMODEL_H_
#define SRC_ENGINE_ENTITY_SUBSYSTEM_PARTICLE_PARTICLEMODEL_H_

#define PARTICLE_SUBSYSTEM "particle"

#define ENTTYPE_PARENT_PARTICLE_TYPE "particle_type"
#define ENTTYPE_PARENT_EMITTER_TYPE "particle_emitter"
#define ENTTYPE_PARENT_INITIALIZER_TYPE "particle_initializer"
#define ENTTYPE_PARENT_MODIFIER_TYPE "particle_modifier"
#define ENTTYPE_PARENT_RENDERER_TYPE "particle_renderer"

#define REL_EMITTED_BY "emitted_by"
#define REL_MODIFIES "modifies"
#define REL_RENDERS "renders"
#define REL_APPLY_INITIALIZER "apply_initializer"
#define REL_APPLY_MODIFIER "apply_modifier"
#define REL_APPLY_RENDERER "apply_renderer"

#define PARTICLE_EMITTER_TYPE_FACTORY "particle_emitter_type_factory"
#define PARTICLE_EMITTER_FUNCTION_ATTRIBUTE_NAME "emit"
#define ENTTYPE_PREFIX_PARTICLE_EMITTER_TYPE "particle_emitter_type_"

#define PARTICLE_INITIALIZER_TYPE_FACTORY "particle_initializer_type_factory"
#define PARTICLE_INITIALIZER_FUNCTION_ATTRIBUTE_NAME "initialize"
#define ENTTYPE_PREFIX_PARTICLE_INITIALIZER_TYPE "particle_initializer_type_"

#define PARTICLE_MODIFIER_TYPE_FACTORY "particle_modifier_type_factory"
#define PARTICLE_MODIFIER_FUNCTION_ATTRIBUTE_NAME "modify"
#define ENTTYPE_PREFIX_PARTICLE_MODIFIER_TYPE "particle_modifier_type_"

#define PARTICLE_TYPE_FACTORY "particle_type_factory"
#define PARTICLE_TYPE_FUNCTION_ATTRIBUTE_NAME ""
#define PARTICLE_TYPE_RENDERER_INSTANCE_ATTRIBUTE_NAME "renderer_instance"
#define ENTTYPE_PREFIX_PARTICLE_TYPE "particle_type_"

// #define ENTTYPE_PARTICLE_EMITTER "particle_emitter"
// #define ENTTYPE_PARTICLE_INITIALIZER "particle_initializer"
// #define ENTTYPE_PARTICLE_MODIFIER "particle_modifier"
// #define RELTYPE_APPLY_MODIFIER_ON_EMITTED_PARTICLES "apply_modifier_on_emitted_particles"
// #define RELTYPE_APPLY_INITIALIZER_ON_EMITTED_PARTICLES "apply_initializer_on_emitted_particles"

#endif /* SRC_ENGINE_ENTITY_SUBSYSTEM_PARTICLE_PARTICLEMODEL_H_ */
