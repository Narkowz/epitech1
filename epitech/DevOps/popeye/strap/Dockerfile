FROM debian:bookworm-slim

RUN apt-get update -yq \
    && apt-get install -yq nodejs npm

COPY src/package.json ./

RUN npm install

COPY src/app.js ./

EXPOSE 3000

CMD ["node", "app.js"]