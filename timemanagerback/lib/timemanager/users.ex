defmodule Timemanager.Users do
  @moduledoc """
  The Users context.
  """

  import Ecto.Query, warn: false
  import Ecto.Query, only: [from: 2]

  alias Timemanager.Repo

  alias Timemanager.Users.User
  @doc """
  Returns the list of users.

  ## Examples

      iex> list_users()
      [%User{}, ...]

  """

  def authenticate_user(username, plain_text_password) do
    query = from u in User, where: u.username == ^username
    case Repo.one(query) do
      nil ->
        Bcrypt.no_user_verify()
        {:error, :invalid_credentials}
      user ->
        if Bcrypt.verify_pass(plain_text_password, user.password) do
          {:ok, user}
        else
          {:error, :invalid_credentials}
        end
    end
  end

  def list_users do
    Repo.all(User)
  end

  @doc """
  retrieve the user by email

  """
  def get_account_by_email!(email) do
    query = from u in "users",
    where: u.email == ^email,
    select: %{email: u.email, id: u.id, password: u.password, role: u.role}
    Repo.one(query)
  end
  # def get_account_by_email!(email), do: Repo.get_by!(User, email)

  @doc """
  Gets a single user.

  Raises `Ecto.NoResultsError` if the User does not exist.

  ## Examples

      iex> get_user!(123)
      %User{}

      iex> get_user!(456)
      ** (Ecto.NoResultsError)

  """
  def get_user!(id), do: Repo.get!(User, id)

  def get_user_by_username!(params), do: Repo.get_by!(User, params)

  @doc """
  Creates a user.

  ## Examples

      iex> create_user(%{field: value})
      {:ok, %User{}}

      iex> create_user(%{field: bad_value})
      {:error, %Ecto.Changeset{}}

  """
  def create_user(attrs \\ %{}) do
    %User{}
    |> User.changeset(attrs)
    |> Repo.insert()
  end

  @doc """
  Updates a user.

  ## Examples

      iex> update_user(user, %{field: new_value})
      {:ok, %User{}}

      iex> update_user(user, %{field: bad_value})
      {:error, %Ecto.Changeset{}}

  """
  def update_user(%User{} = user, attrs) do
    user
    |> User.changeset(attrs)
    |> Repo.update()
  end

  @doc """
  Deletes a user.

  ## Examples

      iex> delete_user(user)
      {:ok, %User{}}

      iex> delete_user(user)
      {:error, %Ecto.Changeset{}}

  """
  def delete_user(%User{} = user) do
    Repo.delete(user)
  end

  @doc """
  Returns an `%Ecto.Changeset{}` for tracking user changes.

  ## Examples

      iex> change_user(user)
      %Ecto.Changeset{data: %User{}}

  """
  def change_user(%User{} = user, attrs \\ %{}) do
    User.changeset(user, attrs)
  end
end
