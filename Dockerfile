FROM alpine:3.14
WORKDIR /app
ADD . /app
RUN apk add build-base