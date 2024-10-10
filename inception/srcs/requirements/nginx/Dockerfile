FROM debian:bullseye

RUN apt-get update && \
    apt-get install -y nginx && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*
#Do I need to download a specific nginx version so its not "latest" ?

#below straight up doesnt work
#COPY /etc/ssl/certs /etc/nginx/certs
#COPY /etc/ssl/private /etc/nginx/private
# We will have to get our certificate and private file somehow, put a pin on it will you
COPY ./nginx.conf /etc/nginx/nginx.conf

CMD ["nginx", "-g", "daemon off;"]
