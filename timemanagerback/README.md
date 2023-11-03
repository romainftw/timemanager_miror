# Timemanager


## Installation

Install postgres, erlang and elixir

`CREATE DATABASE 'database name in devs.exs config file';`


## Environment variables

Install inotify-tools on your machine to read env file.

Add the following variables to a .env file:

`PG_USER` <br />
`PG_PWD` <br />
`PG_DATABASE` <br />

## Folder structure

* **config**: This directory contains the application's configuration files. The main file is `config.exs`, which holds the global configuration for the application, while other specific files may be used for different environments (e.g., `config.dev.exs`, `config.prod.exs`).

* **deps**: This directory holds the application's dependencies. Third-party libraries and packages that you add to your project are downloaded and stored here.

* **lib**: This is the heart of your application. It contains the Elixir source code for your application, including controller, model, view, router modules, and more. Common subdirectories include:

   - `my_app`: The main module of the application, where you'll typically find controller, model, view, pipeline, etc. modules.
   - `my_app_web`: It contains modules specific to the user interface, such as views, templates, channels, etc.

* **priv**: It holds static files and private resources. Common subdirectories include:

   - `static`: You can store static files like CSS, JavaScript, images, etc. These files will be served directly by the web server.
   - `templates`: It contains EEx (Elixir Embedded Elixir) template files used to generate dynamic HTML pages.

* **test**: This directory contains test files for your application. You'll typically find unit tests, integration tests, and functional tests here.

* **assets** (only for Phoenix projects with JavaScript): If you're using Phoenix with front-end features, such as JavaScript, this directory contains the source JavaScript, CSS, and other assets. These files are usually managed with Webpack.

* **mix.exs**: The main configuration file for your application. It contains information about dependencies, custom tasks, and other important configurations.

* **README.md**: A README file for documenting your project.

* **.gitignore**: A file that lists files and directories to ignore when using Git.

* **.formatter.exs**: A configuration file for code formatting, if you're using the `mix format` tool.

* **.iex.exs**: A configuration file for the Elixir Interactive Shell (IEx).

* **mix.lock**: A generated file that records specific versions of your project's dependencies.

This is generally the basic file structure of an Elixir project based on Phoenix. However, the structure may vary slightly depending on the specific needs of your application or the version of Phoenix you're using.

## Run
To start your Phoenix server:

  * Run `mix setup` to install and setup dependencies
  * Start Phoenix endpoint with `mix phx.server` or inside IEx with `iex -S mix phx.server`

Now you can visit [`localhost:4000`](http://localhost:4000) from your browser.

Ready to run in production? Please [check our deployment guides](https://hexdocs.pm/phoenix/deployment.html).

## Learn more

  * Official website: https://www.phoenixframework.org/
  * Guides: https://hexdocs.pm/phoenix/overview.html
  * Docs: https://hexdocs.pm/phoenix
  * Forum: https://elixirforum.com/c/phoenix-forum
  * Source: https://github.com/phoenixframework/phoenix
