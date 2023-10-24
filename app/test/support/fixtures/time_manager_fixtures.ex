defmodule App.TimeManagerFixtures do
  @moduledoc """
  This module defines test helpers for creating
  entities via the `App.TimeManager` context.
  """

  @doc """
  Generate a clock.
  """
  def clock_fixture(attrs \\ %{}) do
    {:ok, clock} =
      attrs
      |> Enum.into(%{
        status: true,
        time: ~N[2023-10-23 10:17:00]
      })
      |> App.TimeManager.create_clock()

    clock
  end
end
