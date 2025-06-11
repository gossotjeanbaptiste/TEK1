# Use the official debian:bookworm-slim image as the base image
FROM debian:bookworm-slim

# Install Node.js and npm
RUN apt-get update && \
    apt-get install -y nodejs npm && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*

# Set the working directory
WORKDIR /app

# Copy the source code into the image
COPY . .

# Install the application's dependencies
RUN npm install

# Expose port 3000
EXPOSE 3000

# Set the command to start the application
CMD ["npm", "start"]
