# Utilisation des images Ubuntu/Debian pour éviter les problèmes de résolution DNS en production
ARG ELIXIR_VERSION=1.15.7
ARG OTP_VERSION=26.0.2
ARG DEBIAN_VERSION=bullseye-20231009-slim

ARG BUILDER_IMAGE="hexpm/elixir:${ELIXIR_VERSION}-erlang-${OTP_VERSION}-debian-${DEBIAN_VERSION}"
ARG RUNNER_IMAGE="debian:${DEBIAN_VERSION}"

# Étape de construction
FROM ${BUILDER_IMAGE} as builder

# Installation des dépendances de construction
RUN apt-get update -y && \
    apt-get install -y build-essential git inotify-tools && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/* /tmp/* /var/tmp/*

# Préparation du répertoire de construction
WORKDIR /app

# Installation de hex et rebar
RUN mix local.hex --force && \
    mix local.rebar --force

# Configuration de l'environnement de construction
ENV MIX_ENV=dev

# Installation des dépendances mix
COPY mix.exs mix.lock ./
RUN mix deps.get --only $MIX_ENV
RUN mkdir config

# Copie des fichiers de configuration
COPY config/config.exs config/${MIX_ENV}.exs config/
RUN mix deps.compile

# Copie du code source
COPY priv priv
COPY lib lib
COPY assets assets

# Compilation des assets et du code
RUN mix assets.deploy && \
    mix compile

# Copie des fichiers de configuration runtime
COPY config/runtime.exs config/
COPY rel rel
RUN mix release

# Étape de lancement
FROM ${RUNNER_IMAGE}

# Installation de Tini
RUN apt-get update -y && \
    apt-get install -y tini libstdc++6 openssl libncurses5 locales ca-certificates && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/* /tmp/* /var/tmp/*

# Configuration des locales
RUN sed -i '/en_US.UTF-8/s/^# //g' /etc/locale.gen && locale-gen
ENV LANG en_US.UTF-8
ENV LANGUAGE en_US:en
ENV LC_ALL en_US.UTF-8

# Configuration du répertoire de travail et des permissions
WORKDIR /app
RUN chown nobody /app

# Configuration de l'environnement de lancement
ENV MIX_ENV=dev

# Copie du release depuis l'étape de construction
COPY --from=builder --chown=nobody:root /app/_build/${MIX_ENV}/rel/timemanager ./

# Utilisation de l'utilisateur non privilégié
USER nobody

# Configuration de Tini comme ENTRYPOINT
ENTRYPOINT ["/usr/bin/tini", "--"]

# Exposition du port
EXPOSE 4000

# Commande de lancement de l'application
CMD ["/app/bin/timemanager", "start"]
