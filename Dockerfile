# Build Stage
FROM ubuntu:20.04 as builder

## Install build dependencies.
RUN apt-get update && \
    DEBIAN_FRONTEND=noninteractive apt-get install -y cmake clang curl git-all build-essential
COPY . /rapidjson
WORKDIR /rapidjson/
RUN mkdir build
WORKDIR /rapidjson/build
RUN cmake ..
RUN make

# Package Stage
#FROM ubuntu:20.04
#COPY --from=builder /http/fuzz/target/x86_64-unknown-linux-gnu/release/* /
#COPY --from=builder /Mayhemfile /Mayhemfile