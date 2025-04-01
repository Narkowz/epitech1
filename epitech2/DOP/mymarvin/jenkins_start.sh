#!/bin/bash

docker image rm my_marvin
docker build -t my_marvin .
docker run --rm -p 8080:8080 my_marvin
