

defmodule Timemanager.Users.User do
  use Ecto.Schema
  import Ecto.Changeset
  alias Bcrypt


  schema "users" do
    field :username, :string
    field :email, :string
    field :password, :string
    field :role, :string

    timestamps(type: :utc_datetime)
  end

  @roles ~w(manager employee admin teamLead)a
  @doc false
  def changeset(user, attrs) do
    user
    |> cast(attrs, [:username, :email, :password, :role])
    |> validate_required([:username, :email, :password, :role], message: "champs obligatoires")
    |> validate_format(:email,~r/^[A-Za-z0-9\._%+-]+@[A-Za-z0-9.-]+\.[A-Za-z]{2,6}$/,message: "l'email n'est pas valide")
    |> validate_format(:password,~r/^(?=.*[a-z])(?=.*[A-Z])(?=.*\d)(?=.*[!@#$%^&*]).{8,}$/,message: "le mot de passe doit contenir au moins une lettre miniscule une lettre majuscule un chiffre et un caractère spécial !@#$%^&* ")
    # |> check_role()
    |> unique_constraint(:email, message: "cet email est déjà utilisé")
    |> put_password_hash()
  end

  defp check_role(changeset) do

    role = get_field(changeset, :role)

    IO.inspect(role)
    IO.inspect(@roles)
    IO.inspect(changeset)
    if !Enum.member?(@roles, role) do
      add_error(changeset, :role, "le rôle n'est pas valide. Rôles autorisés : " <> Enum.join(@roles, ", "))    else
      changeset
    end
  end

  defp put_password_hash(%Ecto.Changeset{valid?: true, changes: %{password: password}} = changeset) do
    change(changeset, password: Bcrypt.hash_pwd_salt(password))
  end

  defp put_password_hash(changeset), do: changeset
end
