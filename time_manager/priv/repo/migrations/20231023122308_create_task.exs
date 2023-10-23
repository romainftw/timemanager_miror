defmodule TimeManager.Repo.Migrations.CreateTask do
  use Ecto.Migration

  def change do
    create table(:task) do
      add :title, :string
      add :description, :string
      add :status, :boolean, default: false, null: false
      add :user, :integer

      timestamps(type: :utc_datetime)
    end
  end
end
