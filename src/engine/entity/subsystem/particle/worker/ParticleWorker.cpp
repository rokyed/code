/*
 * ParticleWorker.cpp
 *
 *  Created on: 31.01.2015
 *      Author: aschaeffer
 */

#include "ParticleWorker.h"

ParticleWorker::ParticleWorker()
    : name(""), running (false), stopped (true), thread (NULL), function(NULL)
{
    ResetTimer();
}

ParticleWorker::ParticleWorker(std::string name, FunctionRefPtr function)
    : name(name), running (false), stopped (true), thread (NULL), function(function)
{
    ResetTimer();
}

ParticleWorker::~ParticleWorker()
{
    // Just be sure to stop the thread, but shutdown is controlled by ParticleSubsystem
    Stop();
}

void ParticleWorker::Start()
{
    if (stopped)
    {
        logoutf("Starting default worker thread %s", name.c_str());
        thread = SDL_CreateThread(Work, name.c_str(), this);
    }
}

void ParticleWorker::Stop()
{
    if (!stopped)
    {
        running = false;
// SDL_KillThread(thread);
        logoutf("Stopping worker thread %s", name.c_str());
        int retValue;
        SDL_WaitThread(thread, &retValue);
    }
}

int ParticleWorker::Work(void *data)
{
    ParticleWorker *w = (ParticleWorker *) data;
    try
    {
        w->running = true;
        w->stopped = false;
        logoutf("Worker thread started");
        while (w->running)
        {
            w->frame_millis = SDL_GetTicks();
            limitfps(w->frame_millis, w->frame_last_millis);
            if (!game::ispaused())
            {
                w->elapsed_millis = w->frame_millis - w->frame_last_millis;
                TimeStep time_step(
                    w->elapsed_millis,
                    (double) w->elapsed_millis / w->time_unit,
                    w->time_unit
                );

                w->function->Execute(time_step);

                // CAUTION: This applies for modifiers only!
                //
                // 1. Get all relationships of type "modifies" for this modifier
                // w->modifier_instance->GetRelationshipsOfType();
                // 2. Iterate over the relationships
                // 2.1 Call the function
                // w->function->Execute(time_step, w->modifier_instance, particle);
                // w->function->Execute(time_step, w->particle_type, w->emitter_instance);

                // TODO: emitters


                /* TODO: the actual work
                ps.update_particle_pools (elapsedtime);
                ps.emit_particles (elapsedtime);
                ps.modify_particles (elapsedtime);
                */
            }
            w->frame_last_millis = w->frame_millis;
        }
    } catch (int e)
    {
        logoutf("Worker died! e: %d", e);
    }
    w->stopped = true;
    logoutf("Worker thread stopped");
    return 0;
}

std::string ParticleWorker::GetName()
{
    return name;
}

void ParticleWorker::SetFunction(FunctionRefPtr function)
{
    this->function = function;
}

void ParticleWorker::ResetTimer()
{
    frame_millis = frame_last_millis = SDL_GetTicks();
    elapsed_millis = 0;
    time_unit = 1000.0;
}

void ParticleWorker::SetTimeUnit(double time_unit)
{
    this->time_unit = time_unit;
}
