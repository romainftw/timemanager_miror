defmodule Timemanager.Users.Pipeline do
  use Guardian.Plug.Pipeline,
    otp_app: :timemanager,
    error_handler: Timemanager.Users.ErrorHandler,
    module: TimemanagerWeb.Users.Guardian


  # If there is a session token, restrict it to an access token and validate it
  plug Guardian.Plug.VerifySession, claims: %{"typ" => "access"}
  # If there is an authorization header, restrict it to an access token and validate it
  plug Guardian.Plug.VerifyHeader, claims: %{"typ" => "access"}
  # Load the user if either of the verifications worked
  plug Guardian.Plug.LoadResource, allow_blank: true # Change allow_blank to false to ensure user is loaded
  plug Timemanager.Users.CheckAuthenticated # Custom plug to check if the user is authenticated
  # plug Timemanager.Users.RoleCheck # Custom plug to check if the user is authenticated
end
