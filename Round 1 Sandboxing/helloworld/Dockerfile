# set base image (host OS)
FROM ubuntu:latest

# set Python compiler
FROM python:3.7

# copy the content of the local directory to the working directory
COPY . /app

# set the working directory in the container
WORKDIR /app

RUN pip install -r requirements.txt

# command to run on container start
# CMD ["python","./server.py"]
# Or can be written like this
CMD python helloworld.py