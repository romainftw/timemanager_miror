defmodule TimemanagerWeb.Users.Guardian do
  use Guardian, otp_app: :timemanager
  alias Timemanager.Users
  alias Bcrypt

  def subject_for_token(user, _claims) do
    {:ok, to_string(user.id)}
  end

  def subject_for_token(_,_) do
    {:error, :no_id_provided}
  end

  def resource_from_claims(%{"sub" => id}) do
    case  Users.get_user!(String.to_integer(id)) do
      nil -> {:error, :not_found}
      resource -> {:ok, resource}
    end
  end

  def resource_from_claims(_claims) do
    {:error, :no_id_provided}
  end

  def authenticate(email,password) do
    case Users.get_account_by_email!(email) do
      nil -> {:error, :unauthorized}
      user ->
        case validate_password(password, user.password) do
          true  -> create_token(user)
          false -> {:error, :unauthorized}
        end
    end
  end

  defp validate_password(password, hash_password) do
    Bcrypt.verify_pass(password, hash_password)
  end

  defp create_token(user) do
    current_time = System.system_time(:second)
    expiration_time = current_time + 3600 # expiration dans une heure

    claims = %{
      sub: to_string(user.id),
      exp: expiration_time,
      iat: current_time,
      id: user.id
    }
    {:ok,token, _claims} = encode_and_sign(claims,user)
    {:ok, user, token}
  end

end
