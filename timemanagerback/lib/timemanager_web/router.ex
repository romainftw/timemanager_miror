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

    options "/*users", CommonController, :options
    resources "/users", UserController
    get "/user", UserController, :user
    post "/login", UserController, :login

    options "/*clocks", CommonController, :options
    resources "/clocks", ClockController

    options "/*workingtimes", CommonController, :options
    resources "/workingtimes", WorkingtimeController
    get "/workingtimes_start_end/:userID/:start/:end", WorkingtimeController, :showWorkingTimeByUserStartAndEnd
    get "/workingtime_by_user/:userID", WorkingtimeController, :showWorkingtimeByUser
    get "/workingtimes/month_by_user/:userID", WorkingtimeController, :getUserWorkingHours
    get "/workingtimes/day_by_user/:userID", WorkingtimeController, :getUserWorkingHoursToday
    get "/workingtimes/week_by_user/:userID", WorkingtimeController, :getUserWorkingHoursThisWeek
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
