defmodule Timemanager.Authorization do
  alias __MODULE__
  alias Timemanager.Users.User
  alias Timemanager.Workingtimes.Workingtime
  alias Timemanager.Clocks.Clock

  defstruct role: nil, create: %{}, read: %{}, update: %{}, delete: %{}

  def can("admin" = role) do
    grant(role)
    |> all(User)
    |> all(Workingtime)
    |> all(Clock)
  end

  def can("manager" = role) do
    grant(role)
    |> all(User)
    |> all(Workingtime)
    |> all(Clock)
  end

  def can("employee" = role) do
    grant(role)
    |> create(Clock)
    |> read(Workingtime)
  end

  def can("teamLead" = role) do
    grant(role)
    |> create(Clock)
  end

  def can("" = role) do
    grant(role)
    |> create(User)
  end

  def grant(role), do: %Authorization{role: role}

  def read(authorization, resource), do: put_action(authorization, :read, resource)
  def create(authorization, resource), do: put_action(authorization, :create, resource)
  def update(authorization, resource), do: put_action(authorization, :update, resource)
  def delete(authorization, resource), do: put_action(authorization, :delete, resource)

  def read?(authorization, resource) do
    Map.get(authorization.read, resource, false)
  end
  def create?(authorization, resource) do
    Map.get(authorization.create, resource, false)
  end
  def update?(authorization, resource) do
    Map.get(authorization.update, resource, false)
  end
  def delete?(authorization, resource) do
    Map.get(authorization.delete, resource, false)
  end

  def all(authorization, resource) do
    authorization
    |> create(resource)
    |> update(resource)
    |> read(resource)
    |> delete(resource)
  end
  defp put_action(authorization, action, resource) do
    updated_action =
      authorization
      |> Map.get(action)
      |> Map.put(resource, true)

      Map.put(authorization, action, updated_action)
  end
end
