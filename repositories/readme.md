# Repositories

This directory contains one or multiple repositories for media and configuration. By default Inexor provides a core repository named 'inexor-core'.

## Structure of a repository

* /repositories/{name}
* /repositories/{name}/media
* /repositories/{name}/config
* /repositories/{name}/repository.json

## The repository metadata

The file "repository.json" contains the metadata about a repository.

    {
      name: "name",
      description: "A longer description about the repository",
      maintainers: [
        "Name of the first maintainer",
        "Name of the second maintainer"
      ]
    }

## How to add a remote repository (located at GitHub)

    cd repositories
    git clone https://github.com/inexor-game/data.git inexor-core

## How to create a new repository

    cd repositories
    mkdir -p name/media
    mkdir -p name/config
    nano name/repository.json
