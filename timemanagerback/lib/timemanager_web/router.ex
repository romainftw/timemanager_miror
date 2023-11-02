defmodule TimemanagerWeb.Router do
  use TimemanagerWeb, :router

  pipeline :browser do
    plug :accepts, ["html"]
    plug :fetch_session
    plug :fetch_live_flash
    plug :put_root_layout, html: {TimemanagerWeb.Layouts, :root}
    plug :protect_from_forgery
    plug :put_secure_browser_headers
  end

  pipeline :api do
    plug CORSPlug
    plug :accepts, ["json"]
  end

  scope "/", TimemanagerWeb do
    pipe_through :browser

    get "/", PageController, :home
  end

  scope "/api", TimemanagerWeb do
    pipe_through :api

    options "/*users", UserController, :options
    resources "/users", UserController
    get "/user", UserController, :user

    resources "/clocks", ClockController
    resources "/workingtimes", WorkingtimeController
    get "/workingtimes_start_end/:userID", WorkingtimeController, :showWorkingTimeByUserStartAndEnd
    get "/workingtime_by_user/:userID", WorkingtimeController, :showWorkingtimeByUser
  end

  # Enable LiveDashboard and Swoosh mailbox preview in development
  if Application.compile_env(:timemanager, :dev_routes) do
    # If you want to use the LiveDashboard in production, you should put
    # it behind authentication and allow only admins to access it.
    # If your application does not have an admins-only section yet,
    # you can use Plug.BasicAuth to set up some basic authentication
    # as long as you are also using SSL (which you should anyway).
    import Phoenix.LiveDashboard.Router

    scope "/dev" do
      pipe_through :browser

      live_dashboard "/dashboard", metrics: TimemanagerWeb.Telemetry
      forward "/mailbox", Plug.Swoosh.MailboxPreview
    end
  end
end
