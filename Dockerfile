FROM alpine:edge

WORKDIR /NextDate2023

# Copy source files
COPY . .

# Install packages and build project
RUN apk --no-cache add g++ make cmake gtest-dev \
    && cmake . && make

ENTRYPOINT /bin/ash
