FROM ubuntu:22.04

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y \
    g++ \
    python3 \
    python3-pip \
    && pip3 install pytest \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /app

COPY . .

RUN g++ -O2 -std=c++17 lock.cpp -o lock && strip lock

CMD ["/bin/bash"]
