defmodule Timemanager.WorkingtimesTest do
  use Timemanager.DataCase

  alias Timemanager.Workingtimes

  describe "workingtimes" do
    alias Timemanager.Workingtimes.Workingtime

    import Timemanager.WorkingtimesFixtures

    @invalid_attrs %{start: nil, end: nil}

    test "list_workingtimes/0 returns all workingtimes" do
      workingtime = workingtime_fixture()
      assert Workingtimes.list_workingtimes() == [workingtime]
    end

    test "get_workingtime!/1 returns the workingtime with given id" do
      workingtime = workingtime_fixture()
      assert Workingtimes.get_workingtime!(workingtime.id) == workingtime
    end

    test "create_workingtime/1 with valid data creates a workingtime" do
      valid_attrs = %{start: ~N[2023-10-25 09:28:00], end: ~N[2023-10-25 09:28:00]}

      assert {:ok, %Workingtime{} = workingtime} = Workingtimes.create_workingtime(valid_attrs)
      assert workingtime.start == ~N[2023-10-25 09:28:00]
      assert workingtime.end == ~N[2023-10-25 09:28:00]
    end

    test "create_workingtime/1 with invalid data returns error changeset" do
      assert {:error, %Ecto.Changeset{}} = Workingtimes.create_workingtime(@invalid_attrs)
    end

    test "update_workingtime/2 with valid data updates the workingtime" do
      workingtime = workingtime_fixture()
      update_attrs = %{start: ~N[2023-10-26 09:28:00], end: ~N[2023-10-26 09:28:00]}

      assert {:ok, %Workingtime{} = workingtime} = Workingtimes.update_workingtime(workingtime, update_attrs)
      assert workingtime.start == ~N[2023-10-26 09:28:00]
      assert workingtime.end == ~N[2023-10-26 09:28:00]
    end

    test "update_workingtime/2 with invalid data returns error changeset" do
      workingtime = workingtime_fixture()
      assert {:error, %Ecto.Changeset{}} = Workingtimes.update_workingtime(workingtime, @invalid_attrs)
      assert workingtime == Workingtimes.get_workingtime!(workingtime.id)
    end

    test "delete_workingtime/1 deletes the workingtime" do
      workingtime = workingtime_fixture()
      assert {:ok, %Workingtime{}} = Workingtimes.delete_workingtime(workingtime)
      assert_raise Ecto.NoResultsError, fn -> Workingtimes.get_workingtime!(workingtime.id) end
    end

    test "change_workingtime/1 returns a workingtime changeset" do
      workingtime = workingtime_fixture()
      assert %Ecto.Changeset{} = Workingtimes.change_workingtime(workingtime)
    end
  end
end
