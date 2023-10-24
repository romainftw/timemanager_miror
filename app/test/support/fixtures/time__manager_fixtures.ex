defmodule App.Time_ManagerFixtures do
  @moduledoc """
  This module defines test helpers for creating
  entities via the `App.Time_Manager` context.
  """

  @doc """
  Generate a working_time.
  """
  def working_time_fixture(attrs \\ %{}) do
    {:ok, working_time} =
      attrs
      |> Enum.into(%{
        end: ~N[2023-10-23 10:18:00],
        start: ~N[2023-10-23 10:18:00]
      })
      |> App.Time_Manager.create_working_time()

    working_time
  end
end
