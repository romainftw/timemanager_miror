defmodule Timemanager.WorkingtimesFixtures do
  @moduledoc """
  This module defines test helpers for creating
  entities via the `Timemanager.Workingtimes` context.
  """

  @doc """
  Generate a workingtime.
  """
  def workingtime_fixture(attrs \\ %{}) do
    {:ok, workingtime} =
      attrs
      |> Enum.into(%{
        end: ~N[2023-10-25 09:28:00],
        start: ~N[2023-10-25 09:28:00]
      })
      |> Timemanager.Workingtimes.create_workingtime()

    workingtime
  end
end
