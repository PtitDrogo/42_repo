FROM debian:bullseye

RUN apt-get update && \
    apt-get install -y nginx && \
    apt-get install nginx -y && \
    apt-get install openssl -y && \    
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*
#the last two are just there to save spaces on the image creation
#Do I need to download a specific nginx version so its not "latest" ?

#below straight up doesnt work
#COPY /etc/ssl/certs /etc/nginx/certs
#COPY /etc/ssl/private /etc/nginx/private
# We will have to get our certificate and private file somehow, put a pin on it will you

COPY ./conf/nginx.conf /etc/nginx/nginx.conf
#the above line will probably come back into play

RUN mkdir -p /etc/nginx/ssl
RUN openssl req -x509 -nodes -out /etc/nginx/ssl/mycrt.crt -keyout /etc/nginx/ssl/mykey.key -subj "/C=FR/L=LYON/O=42/OU=STUDENT/CN=tfreydie.42.fr"
#req = ask for certificate
#x509 = type of certificat.
#-nodes = to generate a no password key
#-out = where to store the certificate
#-keyout = where to store the key 
RUN mkdir -p /var/run/nginx
RUN chmod 755 /var/www/html
RUN chown -R www-data:www-data /var/www/html
#maybe the above is wrong and needs a space somewhere

CMD ["nginx", "-g", "daemon off;"]
