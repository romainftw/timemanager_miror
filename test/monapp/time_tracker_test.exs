defmodule Todolist.TimeTrackerTest do
  use Todolist.DataCase

  alias Todolist.TimeTracker

  describe "clocks" do
    alias Todolist.TimeTracker.Clock

    import Todolist.TimeTrackerFixtures

    @invalid_attrs %{status: nil, time: nil}

    test "list_clocks/0 returns all clocks" do
      clock = clock_fixture()
      assert TimeTracker.list_clocks() == [clock]
    end

    test "get_clock!/1 returns the clock with given id" do
      clock = clock_fixture()
      assert TimeTracker.get_clock!(clock.id) == clock
    end

    test "create_clock/1 with valid data creates a clock" do
      valid_attrs = %{status: true, time: ~N[2023-10-26 14:31:00]}

      assert {:ok, %Clock{} = clock} = TimeTracker.create_clock(valid_attrs)
      assert clock.status == true
      assert clock.time == ~N[2023-10-26 14:31:00]
    end

    test "create_clock/1 with invalid data returns error changeset" do
      assert {:error, %Ecto.Changeset{}} = TimeTracker.create_clock(@invalid_attrs)
    end

    test "update_clock/2 with valid data updates the clock" do
      clock = clock_fixture()
      update_attrs = %{status: false, time: ~N[2023-10-27 14:31:00]}

      assert {:ok, %Clock{} = clock} = TimeTracker.update_clock(clock, update_attrs)
      assert clock.status == false
      assert clock.time == ~N[2023-10-27 14:31:00]
    end

    test "update_clock/2 with invalid data returns error changeset" do
      clock = clock_fixture()
      assert {:error, %Ecto.Changeset{}} = TimeTracker.update_clock(clock, @invalid_attrs)
      assert clock == TimeTracker.get_clock!(clock.id)
    end

    test "delete_clock/1 deletes the clock" do
      clock = clock_fixture()
      assert {:ok, %Clock{}} = TimeTracker.delete_clock(clock)
      assert_raise Ecto.NoResultsError, fn -> TimeTracker.get_clock!(clock.id) end
    end

    test "change_clock/1 returns a clock changeset" do
      clock = clock_fixture()
      assert %Ecto.Changeset{} = TimeTracker.change_clock(clock)
    end
  end

  describe "workingtimes" do
    alias Todolist.TimeTracker.Workingtime

    import Todolist.TimeTrackerFixtures

    @invalid_attrs %{start: nil, end: nil}

    test "list_workingtimes/0 returns all workingtimes" do
      workingtime = workingtime_fixture()
      assert TimeTracker.list_workingtimes() == [workingtime]
    end

    test "get_workingtime!/1 returns the workingtime with given id" do
      workingtime = workingtime_fixture()
      assert TimeTracker.get_workingtime!(workingtime.id) == workingtime
    end

    test "create_workingtime/1 with valid data creates a workingtime" do
      valid_attrs = %{start: ~N[2023-10-26 14:32:00], end: ~N[2023-10-26 14:32:00]}

      assert {:ok, %Workingtime{} = workingtime} = TimeTracker.create_workingtime(valid_attrs)
      assert workingtime.start == ~N[2023-10-26 14:32:00]
      assert workingtime.end == ~N[2023-10-26 14:32:00]
    end

    test "create_workingtime/1 with invalid data returns error changeset" do
      assert {:error, %Ecto.Changeset{}} = TimeTracker.create_workingtime(@invalid_attrs)
    end

    test "update_workingtime/2 with valid data updates the workingtime" do
      workingtime = workingtime_fixture()
      update_attrs = %{start: ~N[2023-10-27 14:32:00], end: ~N[2023-10-27 14:32:00]}

      assert {:ok, %Workingtime{} = workingtime} = TimeTracker.update_workingtime(workingtime, update_attrs)
      assert workingtime.start == ~N[2023-10-27 14:32:00]
      assert workingtime.end == ~N[2023-10-27 14:32:00]
    end

    test "update_workingtime/2 with invalid data returns error changeset" do
      workingtime = workingtime_fixture()
      assert {:error, %Ecto.Changeset{}} = TimeTracker.update_workingtime(workingtime, @invalid_attrs)
      assert workingtime == TimeTracker.get_workingtime!(workingtime.id)
    end

    test "delete_workingtime/1 deletes the workingtime" do
      workingtime = workingtime_fixture()
      assert {:ok, %Workingtime{}} = TimeTracker.delete_workingtime(workingtime)
      assert_raise Ecto.NoResultsError, fn -> TimeTracker.get_workingtime!(workingtime.id) end
    end

    test "change_workingtime/1 returns a workingtime changeset" do
      workingtime = workingtime_fixture()
      assert %Ecto.Changeset{} = TimeTracker.change_workingtime(workingtime)
    end
  end
end
