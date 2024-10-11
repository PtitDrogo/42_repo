I love Docker so much !
Here are some commands :

- docker ps = check containers
- docker images = check images
- docker build -t mysillyname . = build my images with the name my silly name using the dockerfile at location "."
- docker rmi myimageid = removes the image with the id myimageid
- docker container prune = removes all inactive containers.
- docker stop containerid = stop the running container containerid
- docker run -d -p 3000:3000 imageid = Launch a container using the image imageid in detached state with port binding 3000 to 3000
