defmodule TimeManager.Task do
  use Ecto.Schema
  import Ecto.Changeset

  schema "task" do
    field :status, :boolean, default: false
    field :user, :integer
    field :description, :string
    field :title, :string

    timestamps(type: :utc_datetime)
  end

  @doc false
  def changeset(task, attrs) do
    task
    |> cast(attrs, [:title, :description, :status, :user])
    |> validate_required([:title, :description, :status, :user])
  end
end
