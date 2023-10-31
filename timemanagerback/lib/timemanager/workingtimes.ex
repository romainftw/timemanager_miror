defmodule Timemanager.Workingtimes do
  @moduledoc """
  The Workingtimes context.
  """

  import Ecto.Query, warn: false
  alias Timemanager.Repo

  alias Timemanager.Workingtimes.Workingtime

  @doc """
  Returns the list of workingtimes.

  ## Examples

      iex> list_workingtimes()
      [%Workingtime{}, ...]

  """
 # def list_workingtimes do
    #Repo.all(Workingtime)
  #end
  def list_workingtimes do
    # from(wt in Workingtime, select: wt)
    # query = from wt in "workingtimes",
    # select:  %{id: wt.id, start: wt.start, end: wt.end}
    Repo.all(Workingtime)
  end

  @doc """
  Gets a single workingtime.

  Raises `Ecto.NoResultsError` if the Workingtime does not exist.

  ## Examples

      iex> get_workingtime!(123)
      %Workingtime{}

      iex> get_workingtime!(456)
      ** (Ecto.NoResultsError)

  """
  #def get_workingtime!(id), do: Repo.get!(Workingtime, id)
  def get_workingtime!(id) do
    query = from wt in "workingtimes",
    where: wt.id == ^id,
    select:  %{id: wt.id, start: wt.start, end: wt.end}
    Repo.one(query)
  end
  def get_working_time!(params), do: Repo.get_by!(Workingtime, params)
  def get_workingtime_by_user_id_and_dates!(user_id,start,enddate) do
    query =
      from wt in "workingtimes",

      where: wt.user_id == ^user_id and wt.start >= ^start and wt.end <= ^enddate,
      select: wt

    Repo.one(query)
  end


  def get_workingtime_by_user_id!(user_id) do
    parsed_user_id = String.to_integer(user_id)
    query =
      from wt in "workingtimes",
      where: wt.user_id == ^parsed_user_id ,
      select:  %{id: wt.id, start: wt.start, end: wt.end}

    Repo.all(query)
  end

  def get_workingtimes_by_user_id(user_id) do
    from(w in Workingtime, where: w.user_id == ^user_id) |> Repo.all()
  end

  @doc """
  Creates a workingtime.

  ## Examples

      iex> create_workingtime(%{field: value})
      {:ok, %Workingtime{}}

      iex> create_workingtime(%{field: bad_value})
      {:error, %Ecto.Changeset{}}

  """
  def create_workingtime(attrs \\ %{}) do
    %Workingtime{}
    |> Workingtime.changeset(attrs)
    |> Repo.insert()
  end

  @doc """
  Updates a workingtime.

  ## Examples

      iex> update_workingtime(workingtime, %{field: new_value})
      {:ok, %Workingtime{}}

      iex> update_workingtime(workingtime, %{field: bad_value})
      {:error, %Ecto.Changeset{}}

  """
  def update_workingtime(%Workingtime{} = workingtime, attrs) do
    workingtime
    |> Workingtime.changeset(attrs)
    |> Repo.update()
  end

  @doc """
  Deletes a workingtime.

  ## Examples

      iex> delete_workingtime(workingtime)
      {:ok, %Workingtime{}}

      iex> delete_workingtime(workingtime)
      {:error, %Ecto.Changeset{}}

  """
  def delete_workingtime(%Workingtime{} = workingtime) do
    Repo.delete(workingtime)
  end

  @doc """
  Returns an `%Ecto.Changeset{}` for tracking workingtime changes.

  ## Examples

      iex> change_workingtime(workingtime)
      %Ecto.Changeset{data: %Workingtime{}}

  """
  def change_workingtime(%Workingtime{} = workingtime, attrs \\ %{}) do
    Workingtime.changeset(workingtime, attrs)
  end
end
