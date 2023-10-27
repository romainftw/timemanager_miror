defmodule Todolist.TimeTrackerFixtures do
  @moduledoc """
  This module defines test helpers for creating
  entities via the `Todolist.TimeTracker` context.
  """

  @doc """
  Generate a clock.
  """
  def clock_fixture(attrs \\ %{}) do
    {:ok, clock} =
      attrs
      |> Enum.into(%{
        status: true,
        time: ~N[2023-10-26 14:31:00]
      })
      |> Todolist.TimeTracker.create_clock()

    clock
  end

  @doc """
  Generate a workingtime.
  """
  def workingtime_fixture(attrs \\ %{}) do
    {:ok, workingtime} =
      attrs
      |> Enum.into(%{
        end: ~N[2023-10-26 14:32:00],
        start: ~N[2023-10-26 14:32:00]
      })
      |> Todolist.TimeTracker.create_workingtime()

    workingtime
  end
end
