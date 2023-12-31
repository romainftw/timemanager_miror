# This file is responsible for configuring your application
# and its dependencies with the aid of the Config module.
#
# This configuration file is loaded before any dependency and
# is restricted to this project.

# General application configuration
import Config

config :timemanager,
  ecto_repos: [Timemanager.Repo],
  generators: [timestamp_type: :utc_datetime]

# Configures the endpoint
config :timemanager, TimemanagerWeb.Endpoint,
  url: [host: "localhost"],
  adapter: Phoenix.Endpoint.Cowboy2Adapter,
  render_errors: [
    formats: [html: TimemanagerWeb.ErrorHTML, json: TimemanagerWeb.ErrorJSON],
    layout: false
  ],
  pubsub_server: Timemanager.PubSub,
  live_view: [signing_salt: "lJ0bGIiE"]

# Configures the mailer
#
# By default it uses the "Local" adapter which stores the emails
# locally. You can see the emails in your browser, at "/dev/mailbox".
#
# For production it's recommended to configure a different adapter
# at the `config/runtime.exs`.
config :timemanager, Timemanager.Mailer, adapter: Swoosh.Adapters.Local

# Configure esbuild (the version is required)
config :esbuild,
  version: "0.17.11",
  default: [
    args:
      ~w(js/app.js --bundle --target=es2017 --outdir=../priv/static/assets --external:/fonts/* --external:/images/*),
    cd: Path.expand("../assets", __DIR__),
    env: %{"NODE_PATH" => Path.expand("../deps", __DIR__)}
  ]

# Configure tailwind (the version is required)
config :tailwind,
  version: "3.3.2",
  default: [
    args: ~w(
      --config=tailwind.config.js
      --input=css/app.css
      --output=../priv/static/assets/app.css
    ),
    cd: Path.expand("../assets", __DIR__)
  ]

# Configures Elixir's Logger
config :logger, :console,
  format: "$time $metadata[$level] $message\n",
  metadata: [:request_id]

# Use Jason for JSON parsing in Phoenix
config :phoenix, :json_library, Jason
config :cors_plug,
  send_preflight_response?: false

config :timemanager, TimemanagerWeb.Users.Guardian,
  issuer: "timemanager",
  secret_key: "NAUeCxlFPyiSbnLhqEH0Zszalm1b9Q3J3wW/JW5DFTDQLR6LuRMaGSQ1ZoRPfEJv" # put the result of the mix command above here
# Import environment specific config. This must remain at the bottom
# of this file so it overrides the configuration defined above.
config :timemanager, Timemanager.Repo,
  username: System.get_env("DATABASE_USERNAME") || "postgres",
  password: System.get_env("DATABASE_PASSWORD") || "Epitech1",
  database: System.get_env("DATABASE_NAME"),
  hostname: System.get_env("DATABASE_HOST"),
  port: String.to_integer(System.get_env("DATABASE_PORT") || "5432"),
  pool_size: String.to_integer(System.get_env("DATABASE_POOL_SIZE") || "10"),
  ssl: System.get_env("DATABASE_SSL") == "true"
  
import_config "#{config_env()}.exs"
