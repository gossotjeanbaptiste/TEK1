# * "nginx_id" is the id of nginx in this bootstrap,
# * can be used with other id

docker pull nginx
docker images
docker run nginx # auto remove : docker run --rm nginx
docker ps -a
docker stop "nginx_id"
docker rm "nginx_id"
docker run nginx:1.18 # nginx version 1.18
docker run -d -p 8080:80 nginx:1.18 # with publish port
docker exec "nginx_id" date
docker logs "nginx_id"

